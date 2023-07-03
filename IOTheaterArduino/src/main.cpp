#include <Arduino.h>
#include "model/SmartTheater.h"
#include "kernel/Scheduler.h"
#include "kernel/Task.h"
#include "tasks/CurtainsTask.h"
#include "tasks/MusicTask.h"
#include "tasks/StageLightSystemTask.h"
#include "tasks/AudienceLightSystemTask.h"
#include "tasks/BluetoothMsgTask.h"
#include "tasks/SerialMsgTask.h"
#include "tasks/TimerTask.h"
#include "config.h"


SmartTheater* theater;
Scheduler* scheduler;

void setup() {
  scheduler = new Scheduler();
  scheduler->init(50); 

  /* The code is creating instances of different tasks and passing the `theater` object to them. The
  `theater` object is an instance of the `SmartTheater` class, which represents a theater system.
  Each task is responsible for performing a specific function in the theater system, such as
  controlling curtains, music, stage lights, audience lights, Bluetooth messages, serial messages,
  and timers. By passing the `theater` object to each task, they can access and manipulate the
  theater system as needed. */
  theater = new SmartTheater(LIGHT_AUDIENCE_PIN, LIGHT_R_PIN,LIGHT_G_PIN, LIGHT_B_PIN, CURTAINS_PIN, MUSIC_PIN); 
  Task* curtainsTask = new CurtainsTask(theater);
  Task* musicTask = new MusicTask(theater);
  Task* stageLightSystemTask = new StageLightSystemTask(theater);
  Task* audienceLightSystemTask = new AudienceLightSystemTask(theater);
  Task* bluetoothTask = new BluetoothMsgTask(theater);
  Task* serialTask = new SerialMsgTask(theater);
  Task* timerTask = new TimerTask(theater);


 /* The lines `stageLightSystemTask->init(500);`, `audienceLightSystemTask->init(500);`,
 `musicTask->init(200);`, `curtainsTask->init(500);`, and `timerTask->init(100);` are initializing
 the tasks with specific intervals. */
  stageLightSystemTask->init(500);
  audienceLightSystemTask->init(500);
  musicTask->init(200);
  curtainsTask->init(500);
  timerTask->init(100);
  bluetoothTask->init(500);
  serialTask->init(500);
  
  
 /* The lines `scheduler->addTask(task)` are adding the tasks to the scheduler. The scheduler is
 responsible for managing and executing the tasks at specific intervals. By adding the tasks to the
 scheduler, they will be scheduled and executed according to their specified intervals. */
  scheduler->addTask(bluetoothTask);
  scheduler->addTask(serialTask);

  scheduler->addTask(stageLightSystemTask);
  scheduler->addTask(audienceLightSystemTask);

  scheduler->addTask(musicTask);
  

  scheduler->addTask(curtainsTask);

  
  scheduler->addTask(timerTask);
  

}

void loop() {
  scheduler->schedule();
}
