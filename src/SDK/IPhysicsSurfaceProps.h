#pragma once

struct surfacephysicsparams_t
{
	float friction;
	float elasticity;
	float density;
	float thickness;
	float dampening;
};

struct surfacegameprops_t
{
public:
	float flPenetrationModifier;
	float flDamageModifier;
	unsigned short material;
};

struct surfacedata_t
{
	surfacephysicsparams_t physics;
	char __kisakSucks[68];
	surfacegameprops_t game;
};

class IPhysicsSurfaceProps
{
public:
	virtual ~IPhysicsSurfaceProps(void)
	{}

	// parses a text file containing surface prop keys
	virtual int ParseSurfaceData(const char *pFilename, const char *pTextfile) = 0;

	// current number of entries in the database
	virtual int SurfacePropCount(void) const = 0;

	virtual int GetSurfaceIndex(const char *pSurfacePropName) const = 0;

	virtual void GetPhysicsProperties(int surfaceDataIndex, float *density, float *thickness, float *friction,
	                                  float *elasticity) const = 0;

	virtual surfacedata_t *GetSurfaceData(int surfaceDataIndex) = 0;

	virtual const char *GetString(unsigned short stringTableIndex) const = 0;

	virtual const char *GetPropName(int surfaceDataIndex) const = 0;

	// sets the global index table for world materials
	// UNDONE: Make this per-CPhysCollide
	virtual void SetWorldMaterialIndexTable(int *pMapArray, int mapSize) = 0;

	// NOTE: Same as GetPhysicsProperties, but maybe more convenient
	virtual void GetPhysicsParameters(int surfaceDataIndex, surfacephysicsparams_t *pParamsOut) const = 0;
};
