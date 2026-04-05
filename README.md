# 🌌 Gravity Simulation Engine (C++)

A real-time physics-based gravity simulation built in C++, implementing Newtonian gravitational mechanics and numerical integration to simulate planetary motion and orbital dynamics.

This project demonstrates how fundamental physics equations can be translated into efficient computational systems for real-time simulation and visualization.

---

## 🚀 Features

- 🪐 Real-time N-body gravitational simulation
- 📐 Accurate implementation of Newton's Law of Gravitation
- 🔁 Continuous motion using numerical integration (Euler / improved methods)
- 🎮 Interactive visualization of moving bodies
- ⚡ Efficient update loop for real-time performance
- 🧱 Modular object-oriented architecture

---

## 🧠 Physics Model

The simulation is based on Newtonian gravity:

$$
F = G \frac{m_1 m_2}{r^2}
$$

Each object:
- Exerts gravitational force on every other object
- Updates acceleration using Newton’s Second Law:
  
$$
F = ma \Rightarrow a = \frac{F}{m}
$$

- Updates velocity and position over time using numerical integration

---

## 🏗️ System Architecture

### Core Components

#### 1. Physics Engine
- Computes gravitational forces between all bodies
- Handles vector math (distance, direction, normalization)
- Updates acceleration, velocity, and position

#### 2. Object Model
Each celestial body contains:
- Mass
- Position (x, y)
- Velocity (vx, vy)
- Acceleration (ax, ay)

#### 3. Simulation Loop
- For each frame:
  1. Compute forces
  2. Update acceleration
  3. Update velocity
  4. Update position
  5. Render objects

#### 4. Rendering System
- Displays objects in 2D space
- Updates positions dynamically per frame

---

## 🛠️ Tech Stack

### Language
- **C++**

### Libraries (Typical Implementation)
- **SFML / SDL / OpenGL** (for rendering)
- **GLM** (optional for vector math)
- Standard C++ STL

### Concepts Used
- Object-Oriented Programming (OOP)
- Numerical Methods (Euler Integration)
- Vector Mathematics
- Real-Time Simulation Loops
- Physics Modeling

---

## 🔄 Algorithm (Simplified)

```cpp
for each object i:
    total_force = (0, 0)

    for each object j != i:
        direction = position[j] - position[i]
        distance = magnitude(direction)
        force = G * m[i] * m[j] / (distance * distance)
        total_force += normalize(direction) * force

    acceleration[i] = total_force / m[i]

for each object:
    velocity += acceleration * dt
    position += velocity * dt
