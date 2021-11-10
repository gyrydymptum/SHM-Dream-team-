#include "../include/game/Ship.hpp"
#include "../include/game/ShipBuilder.hpp"
#include "../utility/json/JsonSerializer.hpp"

#include <algorithm>
#include <memory>

Ship::Ship() {}

ShipBuilder Ship::create() {
    return ShipBuilder{new Ship()};
} 
  
const std::string& Ship::getShipType() const { return shipType_; }
const Speed& Ship::getSpeed() const { return speed_; }
const Turning& Ship::getTurning() const { return turning_; }
const Crew& Ship::getCrew() const  { return crew_; }
const Capacity& Ship::getCapacity() const  { return capacity_; }
const Cannons& Ship::getCannons() const  { return cannons_; }
const HP& Ship::getHP() const  { return hp_; }
const Upkeep& Ship::getUpkeep() const  { return upkeep_; }
const Cost& Ship::getCost() const  { return cost_; }
const std::string& Ship::getName() const  { return name_; }


void Ship::setShipType(const std::string& type) {
    shipType_ = type;
}
void Ship::setSpeed(const Speed& speed) {
    speed_ = speed;
}
void Ship::setTurning(const Turning& turning) {
    turning_ = turning;
}
void Ship::setCrew(const Crew& crew) {
    crew_.currentNumber = crew.currentNumber;
}
void Ship::setMaxCrew(const Crew& crew) {
    crew_.max = crew.max;
}
void Ship::setCapacity(const Capacity& capacity) {
    capacity_.currentUsed = capacity.currentUsed;
}
void Ship::setMaxCapacity(const Capacity& capacity) {
    capacity_.max = capacity.max;
}
void Ship::setCannons(const Cannons& cannons) {
    cannons_.currentNumber = cannons.currentNumber;
}
void Ship::setMaxCannons(const Cannons& cannons) {
    cannons_.max = cannons.max;
}
void Ship::setHP(const HP& hp) {
    hp_.currentValue = hp.currentValue;
}
void Ship::setUpkeep(const Upkeep& upkeep) {
    upkeep_ = upkeep;
}
void Ship::setCost(const Cost& cost) {
    cost_ = cost;
}
void Ship::setName(const std::string name) {
    name_ = name; 
}

ShipResponse Ship::subtractCrew( Crew crewNum ) {
    if ( crew_ < crewNum ) {
        return ShipResponse::warningMoreThanYouCan;
    }
    crew_.currentNumber -= crewNum.currentNumber;
    return ShipResponse::done;
}

ShipResponse Ship::subtractCapacity( Capacity capacityNum ) {
    if ( capacity_ < capacityNum ) {
        return ShipResponse::warningMoreThanYouCan;
    }
    capacity_.currentUsed -= capacityNum.currentUsed;
    return ShipResponse::done;
}

ShipResponse Ship::subtractCannons( Cannons cannonsNum ) {
    if ( cannons_ < cannonsNum ) {
        return ShipResponse::warningMoreThanYouCan;
    }
    cannons_.currentNumber -= cannonsNum.currentNumber;
    return ShipResponse::done;
}

// I assume that ship can take big hit during battle and HP can drop below 0
// - in our game there should be
// some mechanism which will be observe current value of HP
ShipResponse Ship::subtractHP( HP hpNum ) {
    hp_.currentValue -= hpNum.currentValue;
    return ShipResponse::done;
}

ShipResponse Ship::addCrew( Crew crewNum ) {
    if ( crew_.max - crew_.currentNumber < crewNum.currentNumber ) {
        return ShipResponse::overcrowdedBoard;
    }
    crew_.currentNumber += crewNum.currentNumber;
    return ShipResponse::done;
}

ShipResponse Ship::addCapacity( Capacity capacityNum ) {
    if ( capacity_.max - capacity_.currentUsed < capacityNum.currentUsed ) {
        return ShipResponse::lackOfSpace;
    }
    capacity_.currentUsed += capacityNum.currentUsed;
    return ShipResponse::done;
}

ShipResponse Ship::addCannons( Cannons cannonsNum ) {
    if ( cannons_.max - cannons_.currentNumber < cannonsNum.currentNumber ) {
        return ShipResponse::lackOfSpace;
    }
    cannons_.currentNumber += cannonsNum.currentNumber;
    return ShipResponse::done;
}

ShipResponse Ship::addHP( HP hpNum ) {
    hp_.currentValue += hpNum.currentValue;
    hp_.currentValue = std::min( hp_.currentValue, hp_.max );
    return ShipResponse::done;
}

template <> Json JsonConvert::to_json(const std::shared_ptr<ShipInterface> &object) {

  Json json;
  json.putValue("shipType", object->getShipType());
  json.putValue("speed", object->getSpeed().value);
  json.putValue("turning", object->getTurning().value);
  json.putValue("crew", object->getCrew().currentNumber);
  json.putValue("maxCrew", object->getCrew().max);
  json.putValue("capacity", object->getCapacity().currentUsed);
  json.putValue("maxCapacity", object->getCapacity().max);
  json.putValue("cannons", object->getCannons().currentNumber);
  json.putValue("maxCannons", object->getCannons().max);
  json.putValue("hp", object->getHP().currentValue);
  json.putValue("upkeep", object->getUpkeep().value);
  json.putValue("cost", object->getCost().value);
  json.putValue("name", object->getName());

  return json;
}

template <> std::shared_ptr<ShipInterface> JsonConvert::from_json(const Json &json) {

  const auto shipType = json.getValue<std::string>("shipType");
  const auto speed = json.getValue<size_t>("speed");
  const auto turning = json.getValue<size_t>("turning");
  const auto crew = json.getValue<size_t>("crew");
  const auto maxCrew = json.getValue<size_t>("maxCrew");
  const auto capacity = json.getValue<size_t>("capacity");
  const auto maxCapacity = json.getValue<size_t>("maxCapacity");
  const auto cannons = json.getValue<size_t>("cannons");
  const auto maxCannons = json.getValue<size_t>("maxCannons");
  const auto hp = json.getValue<int>("hp");
  const auto upkeep = json.getValue<size_t>("upkeep");
  const auto cost = json.getValue<size_t>("cost");
  const auto name = json.getValue<std::string>("name");


  auto ship = Ship::create().setShipType(shipType)
                            .setSpeed(Speed{speed})
                            .setTurning(Turning{turning})
                            .setCrew(Crew{crew, maxCrew})
                            .setMaxCrew(Crew{crew, maxCrew})
                            .setCapacity(Capacity{capacity, maxCapacity})
                            .setMaxCapacity(Capacity{capacity, maxCapacity})
                            .setCannons(Cannons{cannons, maxCannons})
                            .setMaxCannons(Cannons{cannons, maxCannons})
                            .setHP(HP{hp})
                            .setUpkeep(Upkeep{upkeep})
                            .setCost(Cost{cost})
                            .setName(name).get();
  return ship;
} 
