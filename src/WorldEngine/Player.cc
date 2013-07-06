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

void Player::setNbGas(int __nbGas) {
    this->__nbGas = __nbGas;
}

int Player::getNbGas() const {
    return __nbGas;
}

void Player::setNbOre(int __nbOre) {
    this->__nbOre = __nbOre;
}

int Player::getNbOre() const {
    return __nbOre;
}

void Player::setId(int __id) {
    this->__id = __id;
}

int Player::getId() const {
    return this->__id;
}

