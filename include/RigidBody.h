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


    Vector2 Torque()
    { return state.torque; }

    void SetTorque( double x, double y, double z )
    { state.torque.Set( x, y, z ); }

    void SetTorque( const Vector2& v )
    { state.torque = v; }

    void AddTorque( double dx, double dy, double dz )
    { state.torque.Add(dx, dy, dz); }

    void AddTorque( const Vector2& dv )
    { state.torque += dv; }


    void SetShapeParameter( double mass,
                            double hx, double hy, double hz,
                            double restitution_coeff, double friction_coeff );

    Vector2 HalfExtent()
    { return shape.half_extent; }

    double Restitution()
    { return shape.restitution_coefficient; }

    double Friction()
    { return shape.friction_coefficient; }

    double InvMass()
    { return shape.inv_mass; }

    Matrix2 InvInertia()
    { return shape.inv_inertia; }

    Matrix2 InvInertiaWorld()
    { return state.inv_inertia_world; }

    void UpdateInvInertiaWorld();


    rbu32 Attribute()
    { return attribute; }
    void EnableAttribute( rbu32 attr )
    { attribute |= attr; }
    void DisableAttribute( rbu32 attr )
    { attribute &= ~attr; }
    bool AttributeEnabled( rbu32 attr )
    { return (attribute & attr) != 0; }

    bool IsFixed()
    { return (attribute & Attribute_Fixed) != 0; }
    bool IsNotFixed()
    { return (attribute & Attribute_Fixed) == 0; }

    bool Sleeping()
    { return sleep_status.On == true; }
    bool Awake()
    { return sleep_status.On == false; }
    void SetSleepOn()
    { sleep_status.On = true; }
    void SetSleepOff()
    { sleep_status.On = false; }


    void UpdateVelocity( double dt );
    void ApplyImpulse( const Vector2& impulse, const Vector2& relative_position );
    void CorrectVelocity();
    void UpdatePosition( double dt );
    void UpdateSleepStatus( double dt );

    void ClearSolverWorkArea()
    { solver_work_area.Clear(); }

    void ClearSleepStatus()
    { sleep_status.Clear(); }

    void ResetStatuses()
    {
        ClearSolverWorkArea();
        ClearSleepStatus();
    }

private:
    State state;
    Body body;
    LifeSolver solver;
};
