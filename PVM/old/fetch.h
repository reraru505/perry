#pragma once

#include "m_types.h"

void init_cpu(cpu * c , u32 * code , int len);

void fetch(cpu * c , u32 * code);
