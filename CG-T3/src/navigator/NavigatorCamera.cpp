#include "navigator/NavigatorCamera.h"

void NavigatorCamera::Init()
{
	m_yaw = 0.0;
	m_pitch = 0.0;

	SetPos(0, 0, 0);
}

void NavigatorCamera::Refresh()
{
	// Camera parameter according to Riegl's co-ordinate system
	// x/y for flat, z for height
	m_lx = cos(m_yaw) * cos(m_pitch);
	m_ly = sin(m_pitch);
	m_lz = sin(m_yaw) * cos(m_pitch);

	m_strafe_lx = cos(m_yaw - M_PI_2);
	m_strafe_lz = sin(m_yaw - M_PI_2);

	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	gluLookAt(m_x, m_y, m_z, m_x + m_lx, m_y + m_ly, m_z + m_lz, 0.0,1.0,0.0);

	//printf("Camera: %f %f %f Direction vector: %f %f %f\n", m_x, m_y, m_z, m_lx, m_ly, m_lz);
}

Vertex3D NavigatorCamera::GetPos()
{
    return Vertex3D(-1, m_x, m_y, m_z);
}

void NavigatorCamera::GetPos(float &x, float &y, float &z)
{
    x = m_x;
    y = m_y;
    z = m_z;
}

void NavigatorCamera::SetPos(float x, float y, float z)
{
	m_x = x;
	m_y = y;
	m_z =z;

	Refresh();
}

void NavigatorCamera::GetDirectionVector(float &x, float &y, float &z)
{
    x = m_lx;
    y = m_ly;
    z = m_lz;
}

void NavigatorCamera::Move(float incr, bool flyMode)
{
	if(flyMode)
	{
		float lx = cos(m_yaw)*cos(m_pitch);
		float ly = sin(m_pitch);
		float lz = sin(m_yaw)*cos(m_pitch);

		m_x = m_x + incr*lx;
		m_y = m_y + incr*ly;
		m_z = m_z + incr*lz;
	}
	else
	{
		float lx = cos(m_yaw)*cos(m_pitch);
		float lz = sin(m_yaw)*cos(m_pitch);

		m_x = m_x + incr*lx;
		m_z = m_z + incr*lz;
	}

	Refresh();
}

void NavigatorCamera::Strafe(float incr)
{
	m_x = m_x + incr*m_strafe_lx;
	m_z = m_z + incr*m_strafe_lz;

	Refresh();
}

void NavigatorCamera::Fly(float incr)
{
	m_y = m_y + incr;

	Refresh();
}

void NavigatorCamera::RotateYaw(float angle)
{
	m_yaw += angle;

	Refresh();
}

void NavigatorCamera::RotatePitch(float angle)
{
    const float limit = 89.0 * M_PI_2 / 180.0;

	m_pitch += angle;

    if(m_pitch < -limit)
        m_pitch = -limit;

    if(m_pitch > limit)
        m_pitch = limit;

	Refresh();
}

void NavigatorCamera::SetYaw(float angle)
{
	m_yaw = angle;

	Refresh();
}

void NavigatorCamera::SetPitch(float angle)
{
    m_pitch = angle;

    Refresh();
}
