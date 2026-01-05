#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

/*
Key relationships, with units

1) Force, mass, acceleration

Force (Newtons), mass (kg), and acceleration (m/sec^2): F = m * a

1 N = 1 kg * 1 m / 1 sec^2

2) What is rho (ρ)

rho (ρ) is density, in kg/m^3
It means "mass per volume"

m = rho * V
Units check: (kg/m^3) * (m^3) = kg

3) Gravity

g is acceleration from gravity, in m/sec^2
Weight force of a mass m is: F_gravity = m * g
Units check: (kg) * (m/sec^2) = N

4) Buoyancy in air

Displaced air mass:
m_air_displaced = rho_air * V

Buoyant air force (upward):
F_air = (rho_air * V) * g

Helium mass inside the balloon:
m_He = rho_He * V

Helium weight force (downward):
F_helium = (rho_He * V) * g

Net lifting force available for payload (upward):
F_lift = F_air - F_helium
       = (rho_air - rho_He) * V * g

At lift threshold, the net lift equals the payload weight:
F_lift = m_payload * g

So:
(rho_air - rho_He) * V * g = m_payload * g
g cancels:
(rho_air - rho_He) * V = m_payload
V = m_payload / (rho_air - rho_He)

Helium mass required:
m_He = rho_He * V

5) Ideal gas law, and what is J

Ideal gas law:
P * V = n * R * T

P in Pa
V in m^3
n in mol
R in J/(mol*K)
T in K

J means Joule, the SI unit of energy.
1 J = 1 N * 1 m
1 N = 1 kg * 1 m / 1 sec^2
So 1 J = 1 kg * 1 m^2 / 1 sec^2

6) Density from ideal gas law

n = m / M
m = rho * V

P * V = (rho * V / M) * R * T
Cancel V:
P = (rho / M) * R * T
rho = (P * M) / (R * T)

We use this for both air and helium, so the model is self consistent.
*/

const double G = 9.80665;                     // m/sec^2
const double R = 8.314462618;                 // J/(mol*K)

const double HELIUM_MOLAR_MASS = 0.004002602; // kg/mol
const double AIR_MOLAR_MASS = 0.0289647;      // kg/mol (dry air approximation)

const double P_SINGAPORE = 101325.0; // Pa
const double T_SINGAPORE = 303.15;   // K

const double P_EVEREST = 33700.0;    // Pa
const double T_EVEREST = 253.15;     // K

const double P_NORTH_POLE = 101325.0; // Pa
const double T_NORTH_POLE = 258.15;   // K

double densityFromIdealGas(double pressurePa, double temperatureK, double molarMassKgPerMol) {
    return (pressurePa * molarMassKgPerMol) / (R * temperatureK);
}

 void computeAndPrint(double payloadMassKg,
                    double pressurePa,
                    double temperatureK,
                     const string &locationName) {
    double airDensity = densityFromIdealGas(pressurePa, temperatureK, AIR_MOLAR_MASS);
    double heliumDensity = densityFromIdealGas(pressurePa, temperatureK, HELIUM_MOLAR_MASS);

    double liftPerM3Kg = airDensity - heliumDensity;

    cout << "Location: " << locationName << "\n";
    cout << "  Pressure: " << pressurePa << " Pa\n";
    cout << "  Temperature: " << temperatureK << " K\n";
    cout << "  Air density: " << airDensity << " kg/m^3\n";
    cout << "  Helium density: " << heliumDensity << " kg/m^3\n";

    if (liftPerM3Kg <= 0.0) {
        cout << "  Result: cannot lift payload, because rho_air <= rho_He\n\n";
        return;
    }

    double requiredVolumeM3 = payloadMassKg / liftPerM3Kg;

    // Helium mass required (kg)
    double heliumMassKg = heliumDensity * requiredVolumeM3;

    cout << "  Required helium volume: " << requiredVolumeM3 << " m^3\n";
    cout << "  Helium mass required: " << heliumMassKg << " kg\n\n";
}

int main() {
    double payloadMassKg;
    cin >> payloadMassKg;

    cout << fixed << setprecision(6);
    cout << "Payload mass: " << payloadMassKg << " kg\n\n";

    computeAndPrint(payloadMassKg,
                    P_SINGAPORE,
                    T_SINGAPORE,
                    "Singapore (sea level, warm air)");

    computeAndPrint(payloadMassKg,
                    P_EVEREST,
                    T_EVEREST,
                    "Top of Mount Everest (summit altitude)");

    computeAndPrint(payloadMassKg,
                    P_NORTH_POLE,
                    T_NORTH_POLE,
                    "North Pole (sea level, cold air)");

    return 0;
}

 /* 

        /\_/\    Roberto scincinnea
   ____/ o o \____  AKA mr. <long long>
  /    \  ^  /    \.  he has 2
 /  /\  \___/  /\  \
/__/  \__\_/__/  \__\
\  \   /  _  \    / /
 \  \_/__/ \__\_// /
  \_____/🍆🍆\____/
     🦵      🦵
 
 
   (\_/)
  ( •_•)      "ok... constraints: 2e5"
  / >🍆       "need O(n log n), not vibes"
   U  U
  ┌───────────────────────────────────────┐
  │ A: 3 1 4 1 5 9 2 6 5 3 5              │
  │ goal: min ops to make it strictly purr│
  └───────────────────────────────────────┘

   cat.exe:
     while (WA):
       stare at sample
       add +1 to array
       remove -1 from self-esteem
       mutter: "Fenwick... Fenwick... Fenwick..."

  keyboard:  clack clack clack  ⌨
  verdict:   ✅ AC (0.02s)      🏁
  celebration:
        /\_/\ 
      >( ^.^ )<   "MEOW, I TOTALLY MEANT THAT PROOF"
        (")(")
        (    )
         U🍆U
*/