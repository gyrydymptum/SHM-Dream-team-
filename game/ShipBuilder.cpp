#include "../include/game/Ship.hpp"
#include "../include/game/ShipBuilder.hpp"

ShipBuilder& ShipBuilder::setShipType(const std::string& type){
    ship_->setShipType(type);
    return *this;
}
ShipBuilder& ShipBuilder::setSpeed(const Speed& speed) {
        ship_->setSpeed(speed);
        return *this;
}
ShipBuilder& ShipBuilder::setTurning(const Turning& turning) {
        ship_->setTurning(turning);
        return *this;
}
ShipBuilder& ShipBuilder::setMaxCrew(const Crew& crew) {
        ship_->setMaxCrew(crew);
        return *this;
}
ShipBuilder& ShipBuilder::setMaxCapacity(const Capacity& capacity) {
        ship_->setMaxCapacity(capacity);
        return *this;
}
ShipBuilder& ShipBuilder::setMaxCannons(const Cannons& cannons) {
        ship_->setMaxCannons(cannons);
        return *this;
}
ShipBuilder& ShipBuilder::setUpkeep(const Upkeep& upkeep) {
        ship_->setUpkeep(upkeep);
        return *this;
}
ShipBuilder& ShipBuilder::setCost(const Cost& cost) {
        ship_->setCost(cost);
        return *this;
}
ShipBuilder& ShipBuilder::setName(const std::string& name) {
        ship_->setName(name);
        return *this;
}
ShipBuilder& ShipBuilder::setCrew(const Crew& crew) {
        ship_->setCrew(crew);
        return *this;
}
ShipBuilder& ShipBuilder::setCapacity(const Capacity& capacity) {
        ship_->setCapacity(capacity);
        return *this;
}
ShipBuilder& ShipBuilder::setCannons(const Cannons& cannons) {
        ship_->setCannons(cannons);
        return *this;
}
ShipBuilder& ShipBuilder::setHP(const HP& hp) {
        ship_->setHP(hp);
        return *this;
} 
