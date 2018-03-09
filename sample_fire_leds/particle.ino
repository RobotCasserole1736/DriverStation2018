#include "particle.h"


void initParticle(Particle * in, char startR, char startG, char startB, double max_center_in){
  in->r = startR;
  in->g = startG;
  in->b = startB;

  in->max_center = max_center_in;

  in->width = 5;
  in->center = 0;
  in->move_speed = 1.5;
}


void moveParticle(Particle * in){
  in->center += in->move_speed;

  if(in->center > in->max_center){
    resetParticle(in);
  }
}

void resetParticle(Particle * in){
  in->center = 0;
}

int getRColorAt(Particle * in, double location){
  if(abs(location - in->center) < in->width){
    return in->r;
  } else {
    return 0;
  }
}

int getGColorAt(Particle * in, double location){
  if(abs(location - in->center) < in->width){
    return in->g;
  } else {
    return 0;
  }
}

int getBColorAt(Particle * in, double location){
  if(abs(location - in->center) < in->width){
    return in->b;
  } else {
    return 0;
  }
}

