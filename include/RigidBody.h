#pragma once

#include "vectorMath.h"

class RigidBody {
public:
    struct State {
        Vector2 position;
        Matrix2 orientation;

        Vector2 velocity;
        Vector2 force;
        Matrix2 inverse_inertia;

        Vector2 angular_velocity;
        Vector2 angular_momentum;
        Vector2 torque;

        State();
    };

    struct Body {
        Vector2 half_extent; //TODO

        double inverse_mass;
        Matrix2 inverse_inertia;

        double restitution_coefficient;
        double friction_coefficient;

        Body();
        Body(double x, double y, double mass, double _restitution_coefficient, double _friction_coefficient);
        void Set(double x, double y, double mass, double _restitution_coefficient, double _friction_coefficient);
    };

    struct LifeSolver {
        Vector2 delta_velocity;
        Vector2 delta_angular_momentum;
        Vector2 delta_angular_velocity;

        LifeSolver();
        void Clear();
    };


    RigidBody();

    Vector2 position();
    void setPosition(double x, double y);
    void setPosition(const Vector2& _position);
    void changePosition(double delta_x, double delta_y);
    void changePosition(const Vector2& delta_position);

    Matrix2 orientation();
    Matrix2 orientationTranspose();
    void setOrientation(const Matrix2& _orientation);
    void setOrientation(double radian_x, double radian_y);
    void changeOrientation(double radian_delta_x, double radian_delta_y);

    Vector2 velocity();
    void setVelocity(double x, double y);
    void setVelocity(const Vector2& _velocity);
    void changeVelocity(double delta_x, double delta_y);
    void changeVelocity(const Vector2& delta_velocity);

    Vector2 angularVelocity();
    void setAngularVelocity(double x, double y);
    void setAngularVelocity(const Vector2& _angular_velocity);
    void changeAngularVelocity(double delta_x, double delta_y);
    void changeAngularVelocity(const Vector2& delta_angular_velocity);

    Vector2 angularMomentum();
    void setAngularMomentum(double x, double y);
    void setAngularMomentum(const Vector2& _angular_momentum);
    void changeAngularMomentum(double delta_x, double delta_y);
    void changeAngularMomentum(const Vector2& delta_angular_momentum);

    Vector2 force();
    void setForce(double x, double y);
    void setForce(const Vector2& _force);
    void setForceAt(const Vector2& _force, const Vector2& at);
    void changeForce(double delta_x, double delta_y);
    void changeForce( const Vector2& delta_force);
    void changeForceAt(const Vector2& delta_force, const Vector2& at);

    Vector2 torque();
    void setTorque(double x, double y);
    void setTorque(const Vector2& _torque);
    void changeTorque(double delta_x, double delta_y);
    void changeTorque(const Vector2& delta_torque);

    void setBodyParams(double x, double y, double mass, double _restitution_coefficient, double _friction_coefficient);
    Vector2 halfExtent();
    double restitution();
    double friction();
    double inverseMass();
    Matrix2 inverseInertia();
    Matrix2 inverseInertiaAbsolute();
    void updateInverseInertiaAbsolute();

    void UpdateVelocity( double dt );
    void ApplyImpulse( const Vector2& impulse, const Vector2& relative_position );
    void CorrectVelocity();
    void UpdatePosition( double dt );
    void UpdateSleepStatus( double dt );
    void ClearSolver();
    void ResetStatuses()
    {
//        ClearSolverWorkArea();
    }

private:
    State state;
    Body body;
    LifeSolver solver;
};
