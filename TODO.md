# 🧮 Raytracer Math Library — TODO

Progress checklist for math components of the Raytracer project.  
Grouped by type and category for clarity.

---

## 📦 Vectors

### vec2
- [ ] Construction (zero, one, from scalar/array)
- [ ] Arithmetic (add, sub, mul, div, scale, negate)
- [ ] Geometry (length, normalize, distance, dot, reflect)
- [ ] Utility (min, max, clamp, lerp, equals)

### vec3
- [ ] Construction
- [ ] Arithmetic
- [ ] Geometry (including cross product)
- [ ] Utility

### vec4
- [ ] Construction
- [ ] Arithmetic
- [ ] Geometry
- [ ] Utility

---

## 🧱 Matrices

### mat2
- [ ] Construction (zero, identity)
- [ ] Operations (add, sub, mul, mul_vec, transpose, determinant, inverse)

### mat3
- [ ] Construction
- [ ] Operations
- [ ] Transformations (rotation, scale, translation)

### mat4
- [ ] Construction
- [ ] Operations
- [ ] Transformations (translate, rotate, scale, perspective, lookat)

---

## 🌀 Quaternions
- [ ] Core (identity, from axis-angle, normalize, conjugate, inverse)
- [ ] Operations (multiply, rotate vector, slerp)

---

## 🔧 Transform
- [ ] Compose from components (position, rotation, scale)
- [ ] Convert to mat4
- [ ] Operations (translate, rotate, scale, set dirty, update)

---

## ⚙️ General Math Utilities
- [ ] Scalar operations (clamp, lerp, min, max, abs)
- [ ] Angle conversions (deg <-> rad)
- [ ] Helpers (nearly_equal, smoothstep)

---

## 🧪 Tests
- [ ] Vector tests (`vec2`, `vec3`, `vec4`)
- [ ] Matrix tests (`mat2`, `mat3`, `mat4`)
- [ ] Quaternion tests (`quat`)
- [ ] Transform tests (`transform`)
- [ ] Utility tests
