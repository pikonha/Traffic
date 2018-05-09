#pragma once
#ifndef INCLUDED_CAR_H
#define INCLUDED_CAR_H

class Car
{
   int length;
   int walked;

   int speed;

   int option;
public:
   ~Car() = default;
   Car(const int _speed);   

   void move();

   void setSpeed(const int _speed) { speed = _speed; }

   int getWalked() const { return walked; }
   int getLength() const { return length; }
   int getOption() const { return option; }
};

#endif