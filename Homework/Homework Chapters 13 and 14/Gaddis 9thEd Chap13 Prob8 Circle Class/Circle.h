/* 
 * File:   Circle.cpp
 * Author: Sonya Smalley
 * Created on November 5, 2021, 12:54 PM
 * Purpose: Create a circle class
 */

#ifndef CIRCLE_H
#define CIRCLE_H

class Circle {
private:
    float radius;
    float pi=3.14159f;
public:
    Circle(){ //default constructor
        radius=0.0f;
    }
    Circle(float r){ //constructor accepts radius of the circle
        radius=r;
    }
    void setRad(float r){ //set radius
        radius=r;
    }
    float getRad() const{ //returns the radius
        return radius;
    }
    float getArea() const{ //returns area
        return pi*radius*radius;
    }
    float getDi() const{ //returns diameter
        return radius*2.0;
    }
    float getCmfnc() const{ //returns circumference
        return 2.0*pi*radius;
    }
};

#endif /* CIRCLE_H */

