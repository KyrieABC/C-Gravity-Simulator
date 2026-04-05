# 🌌 N-Body Gravity Simulation Engine (C++ / OpenGL)

A real-time, physics-based N-body simulation engine built in C++ using modern graphics and mathematical libraries. This project models gravitational interactions between multiple bodies using Newtonian mechanics, enhanced with modular system design, collision handling, trajectory visualization, and improved numerical integration.

Designed as a foundation for **physics simulation, robotics environments, and physical AI systems**, this project demonstrates both low-level system implementation and high-level simulation architecture.

---

## 🚀 Key Features

### 🧠 Physics Engine
- Newtonian gravitational model (N-body problem)
- Pairwise force computation (O(n²))
- Mass-based acceleration updates
- Collision detection and body merging

### ⚙️ Advanced Simulation
- Verlet integration for improved numerical stability
- Real-time simulation loop
- Configurable timestep (`dt`)

### 🎨 Visualization
- OpenGL-based rendering pipeline
- Real-time particle rendering
- Orbital trajectory trails (path visualization)

### 🧱 Clean Architecture
- Modular system design:
  - `physics/` → physics engine
  - `renderer/` → rendering pipeline
  - `core/` → data structures
  - `utils/` → numerical methods
- Separation of concerns (physics vs rendering vs control)

---

## 🧠 Physics Model

The simulation is based on Newton’s Law of Gravitation:

$$
F = G \frac{m_1 m_2}{r^2}
$$

Using Newton’s Second Law:

$$
F = ma \Rightarrow a = \frac{F}{m}
$$

Motion is updated using **Verlet integration**:

$$
x_{t+dt} = x_t + v_t dt + \frac{1}{2} a_t dt^2
$$

---

## 🏗️ System Architecture
```
gravity_sim/
│
├── main.cpp
│
├── physics/
│ ├── physics.h
│ ├── physics.cpp
│
├── renderer/
│ ├── renderer.h
│ ├── renderer.cpp
│
├── core/
│ ├── body.h
│
├── utils/
│ ├── integrator.h
```

---

## 🛠️ Tech Stack

### Language
- C++ (C++17)

### Graphics
- OpenGL  
- GLFW  
- GLEW  

### Mathematics
- GLM  

### Toolchain
- MSYS2 + MinGW-w64  
- g++ (GCC)

---

## 🔄 Simulation Workflow

Each frame executes:

1. Compute gravitational forces  
2. Update acceleration  
3. Integrate motion  
4. Handle collisions  
5. Render  

```cpp
for each frame:
    computeForces()
    integrate(dt)
    handleCollisions()
    render()
```

## 💥 Collision Handling
- Detects proximity between bodies
- Merges masses upon collision
- Prevents numerical instability in close-range interactions

## 🌀 Trajectory Visualization
- Stores historical positions of each body
- Renders trails using line strips
- Helps visualize orbital dynamics and system evolution

## ⚡ Performance Considerations
- Time Complexity: O($x^2$)

## 📦 Installation & Setup
### Prerequisites
- MSYS2 (UCRT64 recommended)
- GCC (g++)
- OpenGL support
### Install Dependencies
```Bash
pacman -S --needed \
mingw-w64-ucrt-x86_64-gcc \
mingw-w64-ucrt-x86_64-glfw \
mingw-w64-ucrt-x86_64-glew \
mingw-w64-ucrt-x86_64-glm
```

---

## 🧪 Build & Run
'''Bash
g++ main.cpp -o simulation \
-lglfw3 -lglew32 -lopengl32 -lgdi32

./simulation
'''

---

## 🔮 Future Improvement
- RK4 integrator
- Barnes-Hut optimization
- GPU acceleration
- Interactive UI
- 3D rendering
