const mqtt = require('mqtt');
const express = require('express');
const app = express();
const server = require('http').Server(app);
const io = require('socket.io')(server);
var port = "COM6";
var stageLightsLColorR;
var stageLightsLColorG;
var stageLightsLColorB;
var stageLightsLBrightness;
var curtainsState;
var musicVolume;
var musicSong;
let state = false;
var showStartTime;


const { SerialPort } = require('serialport')
const serialport = new SerialPort({ path: port, baudRate: 9600 })
serialport.on('open', () => {
    console.log('La porta seriale è aperta');
});
let receivedData = ''; // Variabile per memorizzare i dati ricevuti



app.get('/', (req, res) => {
    res.sendFile(__dirname + '/index.html');
});


server.listen(4000, () => {
    console.log('Server avviato sulla porta 4000');
});

// Configurazione del server MQTT
const mqttBroker = "broker.emqx.io";
const mqttPort = 1883;
const mqttTopic = "esp/dati";
const mqttClient = mqtt.connect({
    host: mqttBroker,
    port: mqttPort
});

mqttClient.on('connect', () => {
    console.log('Connesso al broker MQTT');
    mqttClient.subscribe(mqttTopic);
});


serialport.on('data', (data) => {
    receivedData += data.toString(); // Aggiungi i dati alla stringa ricevuta
    // Controlla se la stringa ricevuta contiene un JSON completo
    if (receivedData.includes('\n')) {

        console.log(receivedData);
        const jsonData = JSON.parse(receivedData);
        stageLightsLColorR = jsonData.sLCr;
        stageLightsLColorG = jsonData.sLCg;
        stageLightsLColorB = jsonData.sLCb;
        stageLightsLBrightness = jsonData.sLB;
        curtainsState = jsonData.cS;
        musicVolume = jsonData.mV;
        musicSong = jsonData.mS;
        showStartTime = jsonData.sST;
        state = jsonData.rD;
        if(curtainsState>0) {
            io.emit('curtains', 'red');
        }else{
            io.emit('curtains','grey');
        }
        function componentToHex(c) {
            let hex = c.toString(16);
            return hex.length === 1 ? "0" + hex : hex;
        }
        function rgbToHex(r, g, b) {
            return "#" + componentToHex(r) + componentToHex(g) + componentToHex(b);
        }

        colorRGBHEX = rgbToHex(stageLightsLColorR, stageLightsLColorG, stageLightsLColorB);
        if(!stageLightsLColorR && !stageLightsLColorG && !stageLightsLColorB){
            io.emit('led', 'grey');
        }else{
            io.emit('led', colorRGBHEX);
        }
        var song ='';
        if(musicSong===1){
            song='Tetris';
        }else if(musicSong===2){
            song='Trono di spade';
        }else if(musicSong===3){
            song='Star Wars';

        }else{
            song='NO SONG YET'

        }

        var musicString = 'Song: '+song + " Volume: " + musicVolume;
        io.emit('music',musicString);
        io.emit('music2',musicSong);



        receivedData = '';


    }
});
mqttClient.on('message', (topic, message) => {
    console.log('Ricevuto messaggio MQTT:', message.toString());

    // Esegui il codice ricevuto dal messaggio MQTT

    if (topic === 'esp/dati') {
        var msg = message.toString();


        if (msg === "true") {
            // Effettua l'aggiornamento del colore di spotlight
            if(state) {
                io.emit('spotlight', 'yellow');
                presence = true;
                io.emit('presence', presence);
            }
        } else {
            // Effettua l'aggiornamento del colore di spotlight
            presence = false;
            io.emit('presence', presence);
            io.emit('spotlight', 'grey');
        }
    }
});

