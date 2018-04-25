#ifndef INCLUDED_CAR_H
#define INCLUDED_CAR_H

#pragma once

class Car
{
   int length;
   int walked;

   int speed;
public:
   ~Car() = default;
   Car(const int _speed);   

   void move();

   int setSpeed(const int _speed) { speed = _speed; }

   int getWalked() const { return walked; }
   int getLength() const { return length; }
};

#endif