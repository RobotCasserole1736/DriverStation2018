#ifndef PARTICLE_H
#define PARTICLE_H

struct Particle
{
    //0-255 range
    char r;
    char g;
    char b;

    double width;
    double center;
    double move_speed;

    double max_center;
    
};

void initParticle(Particle * in, char startR, char startG, char startB, double max_center_in);
void moveParticle(Particle * in);
void resetParticle(Particle * in);
int getRColorAt(Particle * in, double location);
int getGColorAt(Particle * in, double location);
int getBColorAt(Particle * in, double location);


#endif
