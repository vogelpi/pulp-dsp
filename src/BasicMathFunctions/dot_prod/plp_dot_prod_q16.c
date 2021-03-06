/* =====================================================================
 * Project:      PULP DSP Library
 * Title:        plp_dot_prod_q16.c
 * Description:  16-bit fixed point scalar dot product
 *
 * $Date:        28. May 2019
 * $Revision:    V0
 *
 * Target Processor: PULP cores
 * ===================================================================== */
/*
 * Copyright (C) 2019 ETH Zurich and University of Bologna.
 *
 * Author: Xiaying Wang, ETH Zurich
 *
 * SPDX-License-Identifier: Apache-2.0
 *
 * Licensed under the Apache License, Version 2.0 (the License); you may
 * not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 * www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an AS IS BASIS, WITHOUT
 * WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 *
 * Notice: project inspired by ARM CMSIS DSP and parts of source code
 * ported and adopted for RISC-V PULP platform from ARM CMSIS DSP
 * released under Copyright (C) 2010-2019 ARM Limited or its affiliates
 * with Apache-2.0.
 */

#include "plp_math.h"

/**
  @ingroup groupMath
 */

/**
  @addtogroup BasicDotProd
  @{
 */

/**
  @brief Glue code for dot product of 16-bit fixed point vectors.
  @param[in]  pSrcA      points to the first input vector [16 bit]
  @param[in]  pSrcB      points to the second input vector [16 bit]
  @param[in]  blockSize  number of samples in each vector
  @param[in]  deciPoint  decimal point for right shift
  @param[out] pRes     output result returned here [32 bit]
  @return        none

  @par Exploiting SIMD instructions
  When the ISA supports, the 16 bit values are packed two by two into 32 bit vectors and then the
  two dot products are performed simultaneously on 32 bit vectors, with 32 bit accumulator.
 */

void plp_dot_prod_q16(const int16_t *__restrict__ pSrcA,
                      const int16_t *__restrict__ pSrcB,
                      uint32_t blockSize,
                      uint32_t deciPoint,
                      int32_t *__restrict__ pRes) {

    if (rt_cluster_id() == ARCHI_FC_CID) {
        plp_dot_prod_q16s_rv32im(pSrcA, pSrcB, blockSize, deciPoint, pRes);
    } else {
        plp_dot_prod_q16s_xpulpv2(pSrcA, pSrcB, blockSize, deciPoint, pRes);
    }
}

/**
  @} end of BasicDotProd group
 */
