#include <cstddef>

struct Speed {
  operator size_t() { return value; }

  size_t value{};
};

struct Turning {
  operator size_t() { return value; }

  size_t value{};
};

struct Crew {
  Crew() {}
  Crew(size_t maxCrew) : max(maxCrew) {}
  Crew(size_t crewNumber, size_t maxCrew)
      : currentNumber(crewNumber), max(maxCrew) {}

  bool operator<(const Crew &other) const {
    return currentNumber < other.currentNumber;
  }

  size_t currentNumber{};
  size_t max{};
};

struct Capacity {
  Capacity() {}
  Capacity(size_t maxCapacity) : max(maxCapacity) {}
  Capacity(size_t usedCapacity, size_t maxCapacity)
      : currentUsed(usedCapacity), max(maxCapacity) {}

  bool operator<(const Capacity &other) const {
    return currentUsed < other.currentUsed;
  }

  size_t currentUsed{};
  size_t max{};
};

struct Cannons {
    Cannons() {}
  Cannons(size_t maxCannons) : max(maxCannons) {}
  Cannons(size_t currentCannonsNumber, size_t maxCannons)
      : currentNumber(currentCannonsNumber), max(maxCannons) {}

  bool operator<(const Cannons &other) const {
    return currentNumber < other.currentNumber;
  }

  size_t currentNumber{};
  size_t max{};
};

struct HP {
    HP() {}
  HP(int currentHPValue)
      : currentValue(currentHPValue) {}

  int currentValue{};
  int max{100};
};

struct Upkeep {
  operator size_t() { return value; }

  size_t value{};
};

struct Cost {
  operator size_t() { return value; }

  size_t value{};
};
 
