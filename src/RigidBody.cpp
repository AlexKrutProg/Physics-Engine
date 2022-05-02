#include "../include/RigidBody.h"
#define zeroVector2
#define identityMatrix2
#define identityVector2

RigidBody::State::State(): position(zeroVector2), orientation(identityMatrix2), velocity(zeroVector2),
                force(zeroVector2), inverse_inertia(identityMatrix2),
                angular_velocity(zeroVector2), angular_momentum(zeroVector2), torque(zeroVector2)
                {}

RigidBody::Body::Body(): half_extent(identityVector2), inverse_mass(1), inverse_inertia(identityMatrix2),
                restitution_coefficient(0.5), friction_coefficient(0.5)
                {}

RigidBody::Body::Body(double x, double y, double mass, double _restitution_coefficient, double _friction_coefficient):
    half_extent(Vector2(x, y)), inverse_mass(1 / mass), restitution_coefficient(_restitution_coefficient),
    friction_coefficient(_friction_coefficient), inverse_inertia(Matrix2(mass * y * y / 2, 0,
                                                                         0, mass * x * x / 2).Invert())
    {}

void RigidBody::Body::Set(double x, double y, double mass, double _restitution_coefficient, double _friction_coefficient) {
    half_extent.Set(x, y);
    inverse_mass = 1 / mass;
    Matrix2 inertia = Matrix2(mass * y * y / 2, 0,
                              0, mass * x * x / 2);
    inverse_inertia = inertia.Invert();
    restitution_coefficient = _restitution_coefficient;
    friction_coefficient = _friction_coefficient;
}

RigidBody::LifeSolver::LifeSolver(): delta_velocity(zeroVector2), delta_angular_velocity(zeroVector2),
                            delta_angular_momentum(zeroVector2) {}

void RigidBody::LifeSolver::Clear() {
    delta_velocity.SetZero();
    delta_angular_velocity.SetZero();
    delta_angular_momentum.SetZero();
}

RigidBody::RigidBody() {

}

Vector2 RigidBody::position() {
    return state.position;
}

void RigidBody::setPosition(double x, double y) {
    state.position = Vector2(x, y);
}

void RigidBody::setPosition(const Vector2& _position) {
    state.position = _position;
}

void RigidBody::changePosition(double delta_x, double delta_y) {
    state.position += Vector2(delta_x, delta_y);
}

void RigidBody::changePosition(const Vector2& delta_position) {
    state.position += delta_position;
}

Matrix2 RigidBody::orientation() {
    return state.orientation;
}

Matrix2 RigidBody::orientationTranspose() {
    return state.orientation.GetTransposed();
}

void RigidBody::setOrientation(const Matrix2& _orientation) {
    state.orientation = _orientation;
}

void RigidBody::setOrientation(double radian_x, double radian_y) {
    state.orientation.SetFromAxisAngle(Vector2(1,0), radian_x);
    state.orientation *= Matrix2().SetFromAxisAngle(Vector2(0, 1), radian_y);
}

void RigidBody::changeOrientation(double radian_delta_x, double radian_delta_y) {
    Matrix2 delta_matrix;
    delta_matrix.SetFromAxisAngle(Vector2(1, 0), radian_delta_x);
    delta_matrix *= Matrix2().SetFromAxisAngle(Vector2(0, 1), radian_delta_y);
    state.orientation = delta_matrix * state.orientation;
}

Vector2 RigidBody::velocity() {
    return state.velocity;
}

void RigidBody::setVelocity(double x, double y) {
    state.velocity.Set(x, y);
}

void RigidBody::setVelocity(const Vector2 &_velocity) {
    state.velocity = _velocity;
}

void RigidBody::changeVelocity(double delta_x, double delta_y) {
    state.velocity.Change(delta_x, delta_y);
}

void RigidBody::changeVelocity(const Vector2 &delta_velocity) {
    state.velocity += delta_velocity;
}

Vector2 RigidBody::angularVelocity() {
    return state.angular_velocity;
}

void RigidBody::setAngularVelocity(double x, double y) {
    state.angular_velocity.Set(x, y);
    state.angular_momentum = state.inverse_inertia * state.angular_velocity;
}

void RigidBody::setAngularVelocity(const Vector2& _angular_velocity) {
    state.angular_velocity = _angular_velocity;
    state.angular_momentum = state.inverse_inertia * state.angular_velocity;
}

void RigidBody::changeAngularVelocity(double delta_x, double delta_y) {
    state.angular_velocity.Change(delta_x, delta_y);
    state.angular_momentum = state.inverse_inertia * state.angular_velocity;
}

void RigidBody::changeAngularVelocity(const Vector2& delta_angular_velocity) {
    state.angular_velocity += delta_angular_velocity;
    state.angular_momentum = state.inverse_inertia * state.angular_velocity;
}

Vector2 RigidBody::angularMomentum() {
    return state.angular_momentum;
}

void RigidBody::setAngularMomentum(double x, double y) {
    state.angular_momentum.Set(x, y);
}

void RigidBody::setAngularMomentum(const Vector2& _angular_momentum) {
    state.angular_momentum = _angular_momentum;
}

void RigidBody::changeAngularMomentum(double delta_x, double delta_y) {
    state.angular_momentum.Change(delta_x, delta_y);
}

void RigidBody::changeAngularMomentum(const Vector2& delta_angular_momentum) {
    state.angular_momentum += delta_angular_momentum;
}

Vector2 RigidBody::force() {
    return state.force;
}

void RigidBody::setForce(double x, double y) {
    state.force.Set(x, y);
}

void RigidBody::setForce(const Vector2 &_force) {
    state.force = _force;
}

void RigidBody::setForceAt(const Vector2 &_force, const Vector2 &at) {

}

void RigidBody::changeForce(double delta_x, double delta_y) {

}

void RigidBody::changeForce(const Vector2 &delta_force) {

}

void RigidBody::changeForceAt(const Vector2 &delta_force, const Vector2 &at) {

}
