#pragma once

#include <cmath>
#include <vector>

double degreeToRad(double degree) {
    return degree / acos(-1);
}

double Clamp(double v, double v_min, double v_max) {
    if (v < v_min)
        return v_min;
    else if (v > v_max)
        return v_max;
    else
        return v;
}

double Sign(double v) {
    return v > 0;
}


struct Vector2 {
    double x, y;

    Vector2(double x_, double y_);

    Vector2() = default;

    Vector2(const Vector2& other) = default;

    Vector2& operator=(const Vector2& other) = default;

    void Set(double x_, double y_);

    void SetZero();

    void Change(double x_, double y_);

    Vector2 operator-() const;

    Vector2 operator+(const Vector2& v) const;

    Vector2& operator+=(const Vector2& v);

    Vector2 operator-(const Vector2& v) const;

    Vector2& operator-=(const Vector2& v);

    Vector2 operator*(double scale) const;

    Vector2& operator*=(double scale);

    Vector2 operator/(double scale) const;

    Vector2& operator/=(double scale);

    double operator*(const Vector2& v) const;

    Vector2 operator%(const Vector2& v) const;

    double Length() const;

    double LengthSquare() const;

    Vector2 GetNormalized() const;

    Vector2& Normalize();

};

const Vector2 zeroVector2 = Vector2(0, 0);
const Vector2 identityVector2 = Vector2(1, 1);

struct Matrix2 {
    std::vector<std::vector<double>> elem = std::vector<std::vector<double>>(2, std::vector<double>(2));

    Matrix2() = default;

    Matrix2(double e00, double e01,
            double e10, double e11);

    Matrix2(const Matrix2& other) = default;

    Matrix2& operator=(const Matrix2& other) = default;

    double& Elem(int row, int col);

    const double& Elem(int row, int col) const;

    Vector2 Row(int i) const;

    Vector2 Column(int i) const;

    void Set(double e00, double e01,
             double e10, double e11);

    void SetZero();

    void SetIdentity();

    Matrix2& SetFromAxisAngle(const Vector2& normalized_axis, double radian);

    void SetAsCrossProductMatrix(const Vector2& v);

    void Orthonormalize();

    void Scale(double f);

    Matrix2 GetTransposed() const;

    Matrix2& Transpose();

    Matrix2 GetInverse() const;

    Matrix2& Invert();

    Matrix2 operator+(const Matrix2& m) const;

    Matrix2& operator+=(const Matrix2& m);

    Matrix2 operator-(const Matrix2& m) const;

    Matrix2& operator-=(const Matrix2& m);

    Matrix2 operator*(double f) const;

    Matrix2& operator*=(double f);

    Matrix2 operator*(const Matrix2& m) const;

    Matrix2& operator*=(const Matrix2& m);

    Vector2 operator*(const Vector2& v) const;

};

const Matrix2 identityMatrix2 = {1, 0, 0, 1};


Vector2::Vector2(double x_, double y_)
        : x(x_), y(y_) {}

void Vector2::Set(double x_, double y_) {
    x = x_;
    y = y_;
}

void Vector2::SetZero() {
    Set(0, 0);
}


Vector2 Vector2::operator-() const {
    return Vector2(-x, -y);
}

Vector2 Vector2::operator+(const Vector2& v) const {
    return Vector2(x + v.x, y + v.y);
}

Vector2& Vector2::operator+=(const Vector2& v) {
    x += v.x;
    y += v.y;
    return *this;
}

Vector2 Vector2::operator-(const Vector2& v) const {
    return Vector2(x - v.x, y - v.y);
}

Vector2& Vector2::operator-=(const Vector2& v) {
    x -= v.x;
    y -= v.y;
    return *this;
}

Vector2 Vector2::operator*(double scale) const {
    return Vector2(x * scale, y * scale);
}

Vector2& Vector2::operator*=(double scale) {
    x *= scale;
    y *= scale;
    return *this;
}

Vector2 Vector2::operator/(double scale) const {
    return Vector2(x / scale, y / scale);
}

Vector2& Vector2::operator/=(double scale) {
    x /= scale;
    y /= scale;
    return *this;
}

double Vector2::operator*(const Vector2& v) const {
    return x * v.x + y * v.y;
}

double Vector2::Length() const {
    return sqrt(x * x + y * y);
}

double Vector2::LengthSquare() const {
    return x * x + y * y;
}

Vector2 Vector2::GetNormalized() const {
    double l = Length();
    return Vector2(x / l, y / l);
}

Vector2& Vector2::Normalize() {
    *this /= Length();
    return *this;
}

Matrix2::Matrix2(double e00, double e01,
                 double e10, double e11) {
    Elem(0, 0) = e00;
    Elem(0, 1) = e01;
    Elem(1, 0) = e10;
    Elem(1, 1) = e11;
}

double& Matrix2::Elem(int row, int col) {
    return elem[row][col];
}

const double& Matrix2::Elem(int row, int col) const {
    return elem[row][col];
}

Vector2 Matrix2::Row(int i) const {
    return Vector2(elem[i][0], elem[i][1]);
}

Vector2 Matrix2::Column(int i) const {
    return Vector2(elem[0][i], elem[1][i]);
}

void Matrix2::Set(double e00, double e01,
                  double e10, double e11) {
    Elem(0, 0) = e00;
    Elem(0, 1) = e01;
    Elem(1, 0) = e10;
    Elem(1, 1) = e11;
}

void Matrix2::SetZero() {
    elem = {{0, 0},
            {0, 0}};
}

void Matrix2::SetIdentity() {
    elem = {{1, 0},
            {0, 1}};
}

void Matrix2::Scale(double f) {
    for (int row = 0; row < 2; ++row)
        for (int col = 0; col < 2; ++col)
            Elem(row, col) *= f;
}

Matrix2 Matrix2::GetTransposed() const {
    auto copy = *this;
    return copy.Transpose();
}

Matrix2& Matrix2::Transpose() {
    std::swap(elem[0][1], elem[1][0]);
    return *this;
}

Matrix2 Matrix2::GetInverse() const {
    auto copy = *this;
    std::swap(copy.elem[0][0], copy.elem[1][1]);
    copy.elem[0][1] *= -1;
    copy.elem[1][0] *= -1;
    double det = elem[0][0] * elem[1][1] - elem[0][1] * elem[1][0];
    copy *= (double) 1 / det;
    return copy;
}

Matrix2& Matrix2::Invert() {
    *this = GetInverse();
    return *this;
}

Matrix2 Matrix2::operator+(const Matrix2& m) const {
    auto copy = *this;
    copy += m;
    return copy;
}

Matrix2& Matrix2::operator+=(const Matrix2& m) {
    for (int i = 0; i < 2; ++i)
        for (int j = 0; j < 2; ++j)
            elem[i][j] += m.elem[i][j];
    return *this;
}

Matrix2 Matrix2::operator-(const Matrix2& m) const {
    auto copy = *this;
    copy -= m;
    return copy;
}

Matrix2& Matrix2::operator-=(const Matrix2& m) {
    for (int i = 0; i < 2; ++i)
        for (int j = 0; j < 2; ++j)
            elem[i][j] -= m.elem[i][j];
    return *this;
}

Matrix2 Matrix2::operator*(double f) const {
    auto copy = *this;
    copy *= f;
    return copy;
}

Matrix2& Matrix2::operator*=(double f) {
    for (int i = 0; i < 2; ++i) {
        for (int j = 0; j < 2; ++j)
            elem[i][j] *= f;
    }
    return *this;
}

Matrix2 Matrix2::operator*(const Matrix2& m) const {
    return Matrix2(elem[0][0] * m.elem[0][0] + elem[0][1] * m.elem[1][0],
                   elem[0][0] * m.elem[0][1] + elem[0][1] * m.elem[1][1],
                   elem[1][0] * m.elem[0][0] + elem[1][1] * m.elem[1][0],
                   elem[1][0] * m.elem[0][1] + elem[1][1] * m.elem[1][1]);
}

Matrix2& Matrix2::operator*=(const Matrix2& m) {
    *this = *this * m;
    return *this;
}

Vector2 Matrix2::operator*(const Vector2& v) const {
    return Vector2(elem[0][0] * v.x + elem[0][1] * v.y,
                elem[1][0] * v.x + elem[1][1] * v.y);
}

Vector2 operator*(double f, const Vector2& v) {
    return v * f;
}

Matrix2 operator*(double f, const Matrix2& m) {
    return m * f;
}