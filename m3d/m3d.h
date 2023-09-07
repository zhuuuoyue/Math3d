#pragma once

#ifdef M3D_EXPORTS
#define M3D_API __declspec(dllexport)
#else
#define M3D_API __declspec(dllimport)
#endif // M3D_EXPORTS
