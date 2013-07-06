#include "Player.hh"

Player::Player() {
}

Player::~Player() {
}

void Player::setNbShip(int __nbShip) {
    this->__nbShip = __nbShip;
}

int Player::getNbShip() const {
    return __nbShip;
}

void Player::setNbPlanets(int __nbPlanets) {
    this->__nbPlanets = __nbPlanets;
}

int Player::getNbPlanets() const {
    return __nbPlanets;
}

void Player::setNbGas(float __nbGas) {
    this->__nbGas = __nbGas;
}

float Player::getNbGas() const {
    return __nbGas;
}

void Player::setNbOre(float __nbOre) {
    this->__nbOre = __nbOre;
}

float Player::getNbOre() const {
    return __nbOre;
}

void Player::setId(int __id) {
    this->__id = __id;
}

int Player::getId() const {
    return this->__id;
}

