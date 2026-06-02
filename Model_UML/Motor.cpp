#include "pch.h"
#include "Motor.h"
ModelMixer::Motor::Motor(int id, String^ nombre, String^ estado, double torque)
    : Actuadores(id, nombre, estado) {
    this->torque = torque;
}