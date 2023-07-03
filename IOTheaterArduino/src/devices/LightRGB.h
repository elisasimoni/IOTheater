#ifndef __LIGHTRGB__
#define __LIGHTRGB__

class LightRGB {
public:
  virtual void setColor(int r, int g, int b) = 0;
  virtual void switchOff() = 0;    
};

#endif
