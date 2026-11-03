#include "superman_returns_init.h"

DEFINE_REX_FUNC(sub_8290C600) {
	REX_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x8279e3fc
	ctx.lr = 0x8290C608;
	__savegprlr_17(ctx, base);
	// stwu r1,-1872(r1)
	ea = -1872 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lwz r11,19424(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 19424);
	// mr r31,r4
	ctx.r31.u64 = ctx.r4.u64;
	// addi r28,r3,19584
	ctx.r28.s64 = ctx.r3.s64 + 19584;
	// li r27,0
	ctx.r27.s64 = 0;
	// mr r4,r28
	ctx.r4.u64 = ctx.r28.u64;
	// stw r11,972(r31)
	REX_STORE_U32(ctx.r31.u32 + 972, ctx.r11.u32);
	// lwz r11,19436(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 19436);
	// lwz r29,1132(r31)
	ctx.r29.u64 = REX_LOAD_U32(ctx.r31.u32 + 1132);
	// lwz r30,984(r31)
	ctx.r30.u64 = REX_LOAD_U32(ctx.r31.u32 + 984);
	// stw r28,184(r1)
	REX_STORE_U32(ctx.r1.u32 + 184, ctx.r28.u32);
	// stw r27,192(r1)
	REX_STORE_U32(ctx.r1.u32 + 192, ctx.r27.u32);
	// stw r11,980(r31)
	REX_STORE_U32(ctx.r31.u32 + 980, ctx.r11.u32);
	// lis r11,-32101
	ctx.r11.s64 = -2103771136;
	// stw r29,80(r1)
	REX_STORE_U32(ctx.r1.u32 + 80, ctx.r29.u32);
	// stw r29,104(r1)
	REX_STORE_U32(ctx.r1.u32 + 104, ctx.r29.u32);
	// lwz r3,416(r11)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r11.u32 + 416);
	// bl 0x8290a448
	ctx.lr = 0x8290C650;
	sub_8290A448(ctx, base);
	// lwz r11,980(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 980);
	// mr r7,r27
	ctx.r7.u64 = ctx.r27.u64;
	// lhz r8,66(r31)
	ctx.r8.u64 = REX_LOAD_U16(ctx.r31.u32 + 66);
	// mr r6,r27
	ctx.r6.u64 = ctx.r27.u64;
	// lhz r9,44(r31)
	ctx.r9.u64 = REX_LOAD_U16(ctx.r31.u32 + 44);
	// stw r27,100(r1)
	REX_STORE_U32(ctx.r1.u32 + 100, ctx.r27.u32);
	// rlwinm r5,r9,31,1,31
	ctx.r5.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 31) & 0x7FFFFFFF;
	// stw r27,116(r1)
	REX_STORE_U32(ctx.r1.u32 + 116, ctx.r27.u32);
	// lwz r10,0(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 0);
	// addi r11,r11,4
	ctx.r11.s64 = ctx.r11.s64 + 4;
	// stw r8,204(r1)
	REX_STORE_U32(ctx.r1.u32 + 204, ctx.r8.u32);
	// mr r8,r27
	ctx.r8.u64 = ctx.r27.u64;
	// clrlwi r20,r10,16
	ctx.r20.u64 = ctx.r10.u32 & 0xFFFF;
	// stw r7,120(r1)
	REX_STORE_U32(ctx.r1.u32 + 120, ctx.r7.u32);
	// stw r6,92(r1)
	REX_STORE_U32(ctx.r1.u32 + 92, ctx.r6.u32);
	// cmplwi cr6,r5,0
	ctx.cr6.compare<uint32_t>(ctx.r5.u32, 0, ctx.xer);
	// stw r5,180(r1)
	REX_STORE_U32(ctx.r1.u32 + 180, ctx.r5.u32);
	// stw r11,128(r1)
	REX_STORE_U32(ctx.r1.u32 + 128, ctx.r11.u32);
	// rlwinm r11,r10,16,22,31
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 16) & 0x3FF;
	// addi r10,r30,-1
	ctx.r10.s64 = ctx.r30.s64 + -1;
	// stw r8,88(r1)
	REX_STORE_U32(ctx.r1.u32 + 88, ctx.r8.u32);
	// stw r27,128(r31)
	REX_STORE_U32(ctx.r31.u32 + 128, ctx.r27.u32);
	// stw r27,132(r31)
	REX_STORE_U32(ctx.r31.u32 + 132, ctx.r27.u32);
	// sth r27,268(r31)
	REX_STORE_U16(ctx.r31.u32 + 268, ctx.r27.u16);
	// stw r11,96(r1)
	REX_STORE_U32(ctx.r1.u32 + 96, ctx.r11.u32);
	// stw r10,132(r1)
	REX_STORE_U32(ctx.r1.u32 + 132, ctx.r10.u32);
	// lhz r10,42(r31)
	ctx.r10.u64 = REX_LOAD_U16(ctx.r31.u32 + 42);
	// rlwinm r9,r10,31,1,31
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 31) & 0x7FFFFFFF;
	// stw r9,124(r1)
	REX_STORE_U32(ctx.r1.u32 + 124, ctx.r9.u32);
	// beq cr6,0x8290d1b0
	if (ctx.cr6.eq) goto loc_8290D1B0;
	// lis r10,-32250
	ctx.r10.s64 = -2113536000;
	// lis r30,2
	ctx.r30.s64 = 131072;
	// addi r22,r10,-496
	ctx.r22.s64 = ctx.r10.s64 + -496;
loc_8290C6D4:
	// cmplw cr6,r8,r11
	ctx.cr6.compare<uint32_t>(ctx.r8.u32, ctx.r11.u32, ctx.xer);
	// stw r7,260(r31)
	REX_STORE_U32(ctx.r31.u32 + 260, ctx.r7.u32);
	// stw r6,264(r31)
	REX_STORE_U32(ctx.r31.u32 + 264, ctx.r6.u32);
	// sth r27,270(r31)
	REX_STORE_U16(ctx.r31.u32 + 270, ctx.r27.u16);
	// bne cr6,0x8290d12c
	if (!ctx.cr6.eq) goto loc_8290D12C;
	// clrlwi r7,r8,31
	ctx.r7.u64 = ctx.r8.u32 & 0x1;
	// lhz r6,42(r31)
	ctx.r6.u64 = REX_LOAD_U16(ctx.r31.u32 + 42);
	// mr r10,r27
	ctx.r10.u64 = ctx.r27.u64;
	// neg r7,r7
	ctx.r7.s64 = static_cast<int64_t>(-ctx.r7.u64);
	// cmplwi cr6,r9,0
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, 0, ctx.xer);
	// and r19,r7,r6
	ctx.r19.u64 = ctx.r7.u64 & ctx.r6.u64;
	// stw r10,108(r1)
	REX_STORE_U32(ctx.r1.u32 + 108, ctx.r10.u32);
	// beq cr6,0x8290d12c
	if (ctx.cr6.eq) goto loc_8290D12C;
loc_8290C708:
	// cmplw cr6,r10,r20
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, ctx.r20.u32, ctx.xer);
	// bne cr6,0x8290d0d0
	if (!ctx.cr6.eq) goto loc_8290D0D0;
	// lwz r9,1124(r31)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r31.u32 + 1124);
	// rlwinm r8,r11,2,0,29
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 2) & 0xFFFFFFFC;
	// lhz r10,42(r31)
	ctx.r10.u64 = REX_LOAD_U16(ctx.r31.u32 + 42);
	// li r25,0
	ctx.r25.s64 = 0;
	// mullw r10,r10,r11
	ctx.r10.s64 = int64_t(ctx.r10.s32) * int64_t(ctx.r11.s32);
	// lwzx r9,r9,r8
	ctx.r9.u64 = REX_LOAD_U32(ctx.r9.u32 + ctx.r8.u32);
	// stw r25,112(r1)
	REX_STORE_U32(ctx.r1.u32 + 112, ctx.r25.u32);
	// addi r9,r9,-1
	ctx.r9.s64 = ctx.r9.s64 + -1;
	// srawi r10,r10,1
	ctx.xer.ca = (ctx.r10.s32 < 0) & ((ctx.r10.u32 & 0x1) != 0);
	ctx.r10.s64 = ctx.r10.s32 >> 1;
	// and r17,r9,r11
	ctx.r17.u64 = ctx.r9.u64 & ctx.r11.u64;
	// lbz r9,0(r29)
	ctx.r9.u64 = REX_LOAD_U8(ctx.r29.u32 + 0);
	// add r10,r10,r20
	ctx.r10.u64 = ctx.r10.u64 + ctx.r20.u64;
	// clrlwi r9,r9,26
	ctx.r9.u64 = ctx.r9.u32 & 0x3F;
	// rlwinm r18,r10,2,0,29
	ctx.r18.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 2) & 0xFFFFFFFC;
	// stw r9,196(r1)
	REX_STORE_U32(ctx.r1.u32 + 196, ctx.r9.u32);
	// b 0x8290c758
	goto loc_8290C758;
loc_8290C750:
	// lwz r29,80(r1)
	ctx.r29.u64 = REX_LOAD_U32(ctx.r1.u32 + 80);
	// lwz r11,96(r1)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r1.u32 + 96);
loc_8290C758:
	// addi r10,r25,59
	ctx.r10.s64 = ctx.r25.s64 + 59;
	// srawi r7,r25,2
	ctx.xer.ca = (ctx.r25.s32 < 0) & ((ctx.r25.u32 & 0x3) != 0);
	ctx.r7.s64 = ctx.r25.s32 >> 2;
	// rlwinm r10,r10,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 2) & 0xFFFFFFFC;
	// cmpwi cr6,r7,0
	ctx.cr6.compare<int32_t>(ctx.r7.s32, 0, ctx.xer);
	// lwzx r9,r10,r31
	ctx.r9.u64 = REX_LOAD_U32(ctx.r10.u32 + ctx.r31.u32);
	// addi r10,r7,65
	ctx.r10.s64 = ctx.r7.s64 + 65;
	// rlwinm r10,r10,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r10,r10,r31
	ctx.r10.u64 = REX_LOAD_U32(ctx.r10.u32 + ctx.r31.u32);
	// add r10,r10,r9
	ctx.r10.u64 = ctx.r10.u64 + ctx.r9.u64;
	// stw r10,188(r1)
	REX_STORE_U32(ctx.r1.u32 + 188, ctx.r10.u32);
	// bne cr6,0x8290c7c4
	if (!ctx.cr6.eq) goto loc_8290C7C4;
	// addi r10,r25,14
	ctx.r10.s64 = ctx.r25.s64 + 14;
	// lwz r9,180(r31)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r31.u32 + 180);
	// rlwinm r8,r11,1,30,30
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 1) & 0x2;
	// lwz r11,112(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 112);
	// srawi r6,r25,1
	ctx.xer.ca = (ctx.r25.s32 < 0) & ((ctx.r25.u32 & 0x1) != 0);
	ctx.r6.s64 = ctx.r25.s32 >> 1;
	// rlwinm r5,r10,1,0,30
	ctx.r5.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 1) & 0xFFFFFFFE;
	// or r10,r8,r6
	ctx.r10.u64 = ctx.r8.u64 | ctx.r6.u64;
	// add r8,r19,r20
	ctx.r8.u64 = ctx.r19.u64 + ctx.r20.u64;
	// addi r6,r10,70
	ctx.r6.s64 = ctx.r10.s64 + 70;
	// rlwinm r8,r8,1,0,30
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 1) & 0xFFFFFFFE;
	// lhzx r10,r5,r31
	ctx.r10.u64 = REX_LOAD_U16(ctx.r5.u32 + ctx.r31.u32);
	// rlwinm r6,r6,1,0,30
	ctx.r6.u64 = __builtin_rotateleft64(ctx.r6.u32 | (ctx.r6.u64 << 32), 1) & 0xFFFFFFFE;
	// add r10,r10,r8
	ctx.r10.u64 = ctx.r10.u64 + ctx.r8.u64;
	// rlwinm r10,r10,5,0,26
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 5) & 0xFFFFFFE0;
	// lhzx r8,r6,r31
	ctx.r8.u64 = REX_LOAD_U16(ctx.r6.u32 + ctx.r31.u32);
	// b 0x8290c7f0
	goto loc_8290C7F0;
loc_8290C7C4:
	// clrlwi r10,r11,31
	ctx.r10.u64 = ctx.r11.u32 & 0x1;
	// lwz r11,116(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 116);
	// addi r9,r25,42
	ctx.r9.s64 = ctx.r25.s64 + 42;
	// addi r8,r10,68
	ctx.r8.s64 = ctx.r10.s64 + 68;
	// rlwinm r9,r9,2,0,29
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 2) & 0xFFFFFFFC;
	// srawi r10,r19,1
	ctx.xer.ca = (ctx.r19.s32 < 0) & ((ctx.r19.u32 & 0x1) != 0);
	ctx.r10.s64 = ctx.r19.s32 >> 1;
	// rlwinm r8,r8,1,0,30
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 1) & 0xFFFFFFFE;
	// add r6,r10,r20
	ctx.r6.u64 = ctx.r10.u64 + ctx.r20.u64;
	// lwzx r10,r9,r31
	ctx.r10.u64 = REX_LOAD_U32(ctx.r9.u32 + ctx.r31.u32);
	// rlwinm r9,r6,5,0,26
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r6.u32 | (ctx.r6.u64 << 32), 5) & 0xFFFFFFE0;
	// lhzx r8,r8,r31
	ctx.r8.u64 = REX_LOAD_U16(ctx.r8.u32 + ctx.r31.u32);
loc_8290C7F0:
	// add r10,r10,r9
	ctx.r10.u64 = ctx.r10.u64 + ctx.r9.u64;
	// extsh r9,r8
	ctx.r9.s64 = ctx.r8.s16;
	// lhz r8,42(r31)
	ctx.r8.u64 = REX_LOAD_U16(ctx.r31.u32 + 42);
	// rlwinm r5,r25,0,30,30
	ctx.r5.u64 = __builtin_rotateleft64(ctx.r25.u32 | (ctx.r25.u64 << 32), 0) & 0x2;
	// add r11,r18,r11
	ctx.r11.u64 = ctx.r18.u64 + ctx.r11.u64;
	// rlwinm r26,r8,31,1,31
	ctx.r26.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 31) & 0x7FFFFFFF;
	// stw r10,84(r1)
	REX_STORE_U32(ctx.r1.u32 + 84, ctx.r10.u32);
	// li r21,1
	ctx.r21.s64 = 1;
	// li r24,0
	ctx.r24.s64 = 0;
	// li r23,0
	ctx.r23.s64 = 0;
	// li r6,0
	ctx.r6.s64 = 0;
	// cmpwi cr6,r5,0
	ctx.cr6.compare<int32_t>(ctx.r5.s32, 0, ctx.xer);
	// bne cr6,0x8290c840
	if (!ctx.cr6.eq) goto loc_8290C840;
	// cmpwi cr6,r17,0
	ctx.cr6.compare<int32_t>(ctx.r17.s32, 0, ctx.xer);
	// beq cr6,0x8290c850
	if (ctx.cr6.eq) goto loc_8290C850;
	// rlwinm r8,r26,2,0,29
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r26.u32 | (ctx.r26.u64 << 32), 2) & 0xFFFFFFFC;
	// subf r8,r8,r11
	ctx.r8.u64 = ctx.r11.u64 - ctx.r8.u64;
	// lwz r8,0(r8)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r8.u32 + 0);
	// cmpwi cr6,r8,16384
	ctx.cr6.compare<int32_t>(ctx.r8.s32, 16384, ctx.xer);
	// bne cr6,0x8290c850
	if (!ctx.cr6.eq) goto loc_8290C850;
loc_8290C840:
	// rlwinm r9,r9,5,0,26
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 5) & 0xFFFFFFE0;
	// li r21,8
	ctx.r21.s64 = 8;
	// subf r24,r9,r10
	ctx.r24.u64 = ctx.r10.u64 - ctx.r9.u64;
	// mr r6,r24
	ctx.r6.u64 = ctx.r24.u64;
loc_8290C850:
	// cntlzw r9,r7
	ctx.r9.u64 = ctx.r7.u32 == 0 ? 32 : __builtin_clz(ctx.r7.u32);
	// rlwinm r9,r9,27,31,31
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 27) & 0x1;
	// and r9,r9,r25
	ctx.r9.u64 = ctx.r9.u64 & ctx.r25.u64;
	// cmpwi cr6,r9,0
	ctx.cr6.compare<int32_t>(ctx.r9.s32, 0, ctx.xer);
	// bne cr6,0x8290c878
	if (!ctx.cr6.eq) goto loc_8290C878;
	// cmpwi cr6,r20,0
	ctx.cr6.compare<int32_t>(ctx.r20.s32, 0, ctx.xer);
	// beq cr6,0x8290cab8
	if (ctx.cr6.eq) goto loc_8290CAB8;
	// lwz r9,-4(r11)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r11.u32 + -4);
	// cmpwi cr6,r9,16384
	ctx.cr6.compare<int32_t>(ctx.r9.s32, 16384, ctx.xer);
	// bne cr6,0x8290cab8
	if (!ctx.cr6.eq) goto loc_8290CAB8;
loc_8290C878:
	// addi r23,r10,-32
	ctx.r23.s64 = ctx.r10.s64 + -32;
	// li r21,1
	ctx.r21.s64 = 1;
	// mr r6,r23
	ctx.r6.u64 = ctx.r23.u64;
	// cmplwi cr6,r23,0
	ctx.cr6.compare<uint32_t>(ctx.r23.u32, 0, ctx.xer);
	// beq cr6,0x8290ce0c
	if (ctx.cr6.eq) goto loc_8290CE0C;
	// cmplwi cr6,r24,0
	ctx.cr6.compare<uint32_t>(ctx.r24.u32, 0, ctx.xer);
	// beq cr6,0x8290cab8
	if (ctx.cr6.eq) goto loc_8290CAB8;
	// clrlwi r10,r25,30
	ctx.r10.u64 = ctx.r25.u32 & 0x3;
	// li r5,0
	ctx.r5.s64 = 0;
	// cmpwi cr6,r10,0
	ctx.cr6.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// beq cr6,0x8290c8ac
	if (ctx.cr6.eq) goto loc_8290C8AC;
	// cmpwi cr6,r7,0
	ctx.cr6.compare<int32_t>(ctx.r7.s32, 0, ctx.xer);
	// beq cr6,0x8290c8c4
	if (ctx.cr6.eq) goto loc_8290C8C4;
loc_8290C8AC:
	// addi r10,r26,1
	ctx.r10.s64 = ctx.r26.s64 + 1;
	// rlwinm r10,r10,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 2) & 0xFFFFFFFC;
	// subf r11,r10,r11
	ctx.r11.u64 = ctx.r11.u64 - ctx.r10.u64;
	// lwz r11,0(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 0);
	// cmpwi cr6,r11,16384
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 16384, ctx.xer);
	// bne cr6,0x8290c8cc
	if (!ctx.cr6.eq) goto loc_8290C8CC;
loc_8290C8C4:
	// lhz r11,-16(r24)
	ctx.r11.u64 = REX_LOAD_U16(ctx.r24.u32 + -16);
	// extsh r5,r11
	ctx.r5.s64 = ctx.r11.s16;
loc_8290C8CC:
	// lhz r11,16(r24)
	ctx.r11.u64 = REX_LOAD_U16(ctx.r24.u32 + 16);
	// lhz r10,0(r23)
	ctx.r10.u64 = REX_LOAD_U16(ctx.r23.u32 + 0);
	// lbz r9,19(r31)
	ctx.r9.u64 = REX_LOAD_U8(ctx.r31.u32 + 19);
	// extsh r4,r11
	ctx.r4.s64 = ctx.r11.s16;
	// extsh r3,r10
	ctx.r3.s64 = ctx.r10.s16;
	// cmplwi cr6,r9,0
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, 0, ctx.xer);
	// beq cr6,0x8290ca88
	if (ctx.cr6.eq) goto loc_8290CA88;
	// cmpwi cr6,r25,0
	ctx.cr6.compare<int32_t>(ctx.r25.s32, 0, ctx.xer);
	// beq cr6,0x8290c9d4
	if (ctx.cr6.eq) goto loc_8290C9D4;
	// cmpwi cr6,r25,4
	ctx.cr6.compare<int32_t>(ctx.r25.s32, 4, ctx.xer);
	// beq cr6,0x8290c9d4
	if (ctx.cr6.eq) goto loc_8290C9D4;
	// cmpwi cr6,r25,5
	ctx.cr6.compare<int32_t>(ctx.r25.s32, 5, ctx.xer);
	// beq cr6,0x8290c9d4
	if (ctx.cr6.eq) goto loc_8290C9D4;
	// cmpwi cr6,r25,1
	ctx.cr6.compare<int32_t>(ctx.r25.s32, 1, ctx.xer);
	// bne cr6,0x8290c974
	if (!ctx.cr6.eq) goto loc_8290C974;
	// rlwinm r10,r26,3,0,28
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r26.u32 | (ctx.r26.u64 << 32), 3) & 0xFFFFFFF8;
	// lwz r11,152(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 152);
	// subf r9,r10,r29
	ctx.r9.u64 = ctx.r29.u64 - ctx.r10.u64;
	// lbz r10,0(r29)
	ctx.r10.u64 = REX_LOAD_U8(ctx.r29.u32 + 0);
	// clrlwi r10,r10,26
	ctx.r10.u64 = ctx.r10.u32 & 0x3F;
	// rlwinm r8,r10,2,0,29
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 2) & 0xFFFFFFFC;
	// lbz r9,0(r9)
	ctx.r9.u64 = REX_LOAD_U8(ctx.r9.u32 + 0);
	// add r10,r10,r8
	ctx.r10.u64 = ctx.r10.u64 + ctx.r8.u64;
	// clrlwi r9,r9,26
	ctx.r9.u64 = ctx.r9.u32 & 0x3F;
	// rlwinm r8,r10,2,0,29
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 2) & 0xFFFFFFFC;
	// rlwinm r10,r9,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 2) & 0xFFFFFFFC;
	// add r8,r8,r11
	ctx.r8.u64 = ctx.r8.u64 + ctx.r11.u64;
	// add r10,r9,r10
	ctx.r10.u64 = ctx.r9.u64 + ctx.r10.u64;
	// rlwinm r9,r10,2,0,29
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 2) & 0xFFFFFFFC;
	// lwz r10,16(r8)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r8.u32 + 16);
	// add r11,r9,r11
	ctx.r11.u64 = ctx.r9.u64 + ctx.r11.u64;
	// rlwinm r10,r10,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 2) & 0xFFFFFFFC;
	// lwz r11,16(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 16);
	// lwzx r10,r10,r22
	ctx.r10.u64 = REX_LOAD_U32(ctx.r10.u32 + ctx.r22.u32);
	// mullw r11,r10,r11
	ctx.r11.s64 = int64_t(ctx.r10.s32) * int64_t(ctx.r11.s32);
	// mullw r10,r11,r5
	ctx.r10.s64 = int64_t(ctx.r11.s32) * int64_t(ctx.r5.s32);
	// mullw r11,r11,r4
	ctx.r11.s64 = int64_t(ctx.r11.s32) * int64_t(ctx.r4.s32);
	// add r10,r10,r30
	ctx.r10.u64 = ctx.r10.u64 + ctx.r30.u64;
	// add r11,r11,r30
	ctx.r11.u64 = ctx.r11.u64 + ctx.r30.u64;
	// srawi r5,r10,18
	ctx.xer.ca = (ctx.r10.s32 < 0) & ((ctx.r10.u32 & 0x3FFFF) != 0);
	ctx.r5.s64 = ctx.r10.s32 >> 18;
	// srawi r4,r11,18
	ctx.xer.ca = (ctx.r11.s32 < 0) & ((ctx.r11.u32 & 0x3FFFF) != 0);
	ctx.r4.s64 = ctx.r11.s32 >> 18;
	// b 0x8290ca88
	goto loc_8290CA88;
loc_8290C974:
	// cmpwi cr6,r25,2
	ctx.cr6.compare<int32_t>(ctx.r25.s32, 2, ctx.xer);
	// bne cr6,0x8290ca88
	if (!ctx.cr6.eq) goto loc_8290CA88;
	// lbz r10,-8(r29)
	ctx.r10.u64 = REX_LOAD_U8(ctx.r29.u32 + -8);
	// lbz r9,0(r29)
	ctx.r9.u64 = REX_LOAD_U8(ctx.r29.u32 + 0);
	// clrlwi r10,r10,26
	ctx.r10.u64 = ctx.r10.u32 & 0x3F;
	// lwz r11,152(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 152);
	// clrlwi r9,r9,26
	ctx.r9.u64 = ctx.r9.u32 & 0x3F;
	// rlwinm r8,r10,2,0,29
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 2) & 0xFFFFFFFC;
	// add r10,r10,r8
	ctx.r10.u64 = ctx.r10.u64 + ctx.r8.u64;
	// rlwinm r8,r9,2,0,29
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 2) & 0xFFFFFFFC;
	// rlwinm r10,r10,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 2) & 0xFFFFFFFC;
	// add r9,r9,r8
	ctx.r9.u64 = ctx.r9.u64 + ctx.r8.u64;
	// add r8,r10,r11
	ctx.r8.u64 = ctx.r10.u64 + ctx.r11.u64;
	// rlwinm r10,r9,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 2) & 0xFFFFFFFC;
	// add r10,r10,r11
	ctx.r10.u64 = ctx.r10.u64 + ctx.r11.u64;
	// lwz r11,16(r8)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r8.u32 + 16);
	// lwz r10,16(r10)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r10.u32 + 16);
	// rlwinm r10,r10,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r10,r10,r22
	ctx.r10.u64 = REX_LOAD_U32(ctx.r10.u32 + ctx.r22.u32);
	// mullw r11,r10,r11
	ctx.r11.s64 = int64_t(ctx.r10.s32) * int64_t(ctx.r11.s32);
	// mullw r10,r11,r5
	ctx.r10.s64 = int64_t(ctx.r11.s32) * int64_t(ctx.r5.s32);
	// add r10,r10,r30
	ctx.r10.u64 = ctx.r10.u64 + ctx.r30.u64;
	// srawi r5,r10,18
	ctx.xer.ca = (ctx.r10.s32 < 0) & ((ctx.r10.u32 & 0x3FFFF) != 0);
	ctx.r5.s64 = ctx.r10.s32 >> 18;
	// b 0x8290ca7c
	goto loc_8290CA7C;
loc_8290C9D4:
	// lbz r8,0(r29)
	ctx.r8.u64 = REX_LOAD_U8(ctx.r29.u32 + 0);
	// rlwinm r10,r26,3,0,28
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r26.u32 | (ctx.r26.u64 << 32), 3) & 0xFFFFFFF8;
	// lbz r9,-8(r29)
	ctx.r9.u64 = REX_LOAD_U8(ctx.r29.u32 + -8);
	// clrlwi r8,r8,26
	ctx.r8.u64 = ctx.r8.u32 & 0x3F;
	// lwz r11,152(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 152);
	// clrlwi r9,r9,26
	ctx.r9.u64 = ctx.r9.u32 & 0x3F;
	// rlwinm r28,r8,2,0,29
	ctx.r28.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 2) & 0xFFFFFFFC;
	// subf r10,r10,r29
	ctx.r10.u64 = ctx.r29.u64 - ctx.r10.u64;
	// add r8,r8,r28
	ctx.r8.u64 = ctx.r8.u64 + ctx.r28.u64;
	// rlwinm r27,r9,2,0,29
	ctx.r27.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 2) & 0xFFFFFFFC;
	// rlwinm r8,r8,2,0,29
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 2) & 0xFFFFFFFC;
	// add r9,r9,r27
	ctx.r9.u64 = ctx.r9.u64 + ctx.r27.u64;
	// add r8,r8,r11
	ctx.r8.u64 = ctx.r8.u64 + ctx.r11.u64;
	// lbz r7,-8(r10)
	ctx.r7.u64 = REX_LOAD_U8(ctx.r10.u32 + -8);
	// rlwinm r9,r9,2,0,29
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 2) & 0xFFFFFFFC;
	// lbz r10,0(r10)
	ctx.r10.u64 = REX_LOAD_U8(ctx.r10.u32 + 0);
	// clrlwi r7,r7,26
	ctx.r7.u64 = ctx.r7.u32 & 0x3F;
	// add r28,r9,r11
	ctx.r28.u64 = ctx.r9.u64 + ctx.r11.u64;
	// clrlwi r10,r10,26
	ctx.r10.u64 = ctx.r10.u32 & 0x3F;
	// lwz r9,16(r8)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r8.u32 + 16);
	// rlwinm r8,r7,2,0,29
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 2) & 0xFFFFFFFC;
	// add r8,r7,r8
	ctx.r8.u64 = ctx.r7.u64 + ctx.r8.u64;
	// rlwinm r9,r9,2,0,29
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 2) & 0xFFFFFFFC;
	// lwz r28,16(r28)
	ctx.r28.u64 = REX_LOAD_U32(ctx.r28.u32 + 16);
	// rlwinm r7,r8,2,0,29
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 2) & 0xFFFFFFFC;
	// rlwinm r8,r10,2,0,29
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 2) & 0xFFFFFFFC;
	// add r7,r7,r11
	ctx.r7.u64 = ctx.r7.u64 + ctx.r11.u64;
	// add r10,r10,r8
	ctx.r10.u64 = ctx.r10.u64 + ctx.r8.u64;
	// rlwinm r10,r10,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 2) & 0xFFFFFFFC;
	// add r11,r10,r11
	ctx.r11.u64 = ctx.r10.u64 + ctx.r11.u64;
	// lwz r10,16(r7)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r7.u32 + 16);
	// lwz r8,16(r11)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r11.u32 + 16);
	// lwzx r11,r9,r22
	ctx.r11.u64 = REX_LOAD_U32(ctx.r9.u32 + ctx.r22.u32);
	// mullw r10,r10,r11
	ctx.r10.s64 = int64_t(ctx.r10.s32) * int64_t(ctx.r11.s32);
	// mullw r9,r8,r11
	ctx.r9.s64 = int64_t(ctx.r8.s32) * int64_t(ctx.r11.s32);
	// mullw r10,r10,r5
	ctx.r10.s64 = int64_t(ctx.r10.s32) * int64_t(ctx.r5.s32);
	// mullw r9,r9,r4
	ctx.r9.s64 = int64_t(ctx.r9.s32) * int64_t(ctx.r4.s32);
	// add r10,r10,r30
	ctx.r10.u64 = ctx.r10.u64 + ctx.r30.u64;
	// add r9,r9,r30
	ctx.r9.u64 = ctx.r9.u64 + ctx.r30.u64;
	// srawi r5,r10,18
	ctx.xer.ca = (ctx.r10.s32 < 0) & ((ctx.r10.u32 & 0x3FFFF) != 0);
	ctx.r5.s64 = ctx.r10.s32 >> 18;
	// mullw r11,r28,r11
	ctx.r11.s64 = int64_t(ctx.r28.s32) * int64_t(ctx.r11.s32);
	// srawi r4,r9,18
	ctx.xer.ca = (ctx.r9.s32 < 0) & ((ctx.r9.u32 & 0x3FFFF) != 0);
	ctx.r4.s64 = ctx.r9.s32 >> 18;
loc_8290CA7C:
	// mullw r11,r11,r3
	ctx.r11.s64 = int64_t(ctx.r11.s32) * int64_t(ctx.r3.s32);
	// add r11,r11,r30
	ctx.r11.u64 = ctx.r11.u64 + ctx.r30.u64;
	// srawi r3,r11,18
	ctx.xer.ca = (ctx.r11.s32 < 0) & ((ctx.r11.u32 & 0x3FFFF) != 0);
	ctx.r3.s64 = ctx.r11.s32 >> 18;
loc_8290CA88:
	// subf r11,r3,r5
	ctx.r11.u64 = ctx.r5.u64 - ctx.r3.u64;
	// subf r10,r4,r5
	ctx.r10.u64 = ctx.r5.u64 - ctx.r4.u64;
	// srawi r9,r11,31
	ctx.xer.ca = (ctx.r11.s32 < 0) & ((ctx.r11.u32 & 0x7FFFFFFF) != 0);
	ctx.r9.s64 = ctx.r11.s32 >> 31;
	// srawi r8,r10,31
	ctx.xer.ca = (ctx.r10.s32 < 0) & ((ctx.r10.u32 & 0x7FFFFFFF) != 0);
	ctx.r8.s64 = ctx.r10.s32 >> 31;
	// xor r11,r11,r9
	ctx.r11.u64 = ctx.r11.u64 ^ ctx.r9.u64;
	// xor r10,r10,r8
	ctx.r10.u64 = ctx.r10.u64 ^ ctx.r8.u64;
	// subf r11,r9,r11
	ctx.r11.u64 = ctx.r11.u64 - ctx.r9.u64;
	// subf r10,r8,r10
	ctx.r10.u64 = ctx.r10.u64 - ctx.r8.u64;
	// cmpw cr6,r11,r10
	ctx.cr6.compare<int32_t>(ctx.r11.s32, ctx.r10.s32, ctx.xer);
	// bge cr6,0x8290cab8
	if (!ctx.cr6.lt) goto loc_8290CAB8;
	// mr r6,r24
	ctx.r6.u64 = ctx.r24.u64;
	// li r21,8
	ctx.r21.s64 = 8;
loc_8290CAB8:
	// cmplwi cr6,r6,0
	ctx.cr6.compare<uint32_t>(ctx.r6.u32, 0, ctx.xer);
	// beq cr6,0x8290ce0c
	if (ctx.cr6.eq) goto loc_8290CE0C;
	// lbz r10,19(r31)
	ctx.r10.u64 = REX_LOAD_U8(ctx.r31.u32 + 19);
	// ld r11,0(r29)
	ctx.r11.u64 = REX_LOAD_U64(ctx.r29.u32 + 0);
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// rldicr r10,r11,1,62
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r11.u64, 1) & 0xFFFFFFFFFFFFFFFE;
	// sradi r10,r10,63
	ctx.xer.ca = (ctx.r10.s64 < 0) & ((ctx.r10.u64 & 0x7FFFFFFFFFFFFFFF) != 0);
	ctx.r10.s64 = ctx.r10.s64 >> 63;
	// extsw r10,r10
	ctx.r10.s64 = ctx.r10.s32;
	// or r21,r10,r21
	ctx.r21.u64 = ctx.r10.u64 | ctx.r21.u64;
	// beq cr6,0x8290ce00
	if (ctx.cr6.eq) goto loc_8290CE00;
	// cmplw cr6,r6,r23
	ctx.cr6.compare<uint32_t>(ctx.r6.u32, ctx.r23.u32, ctx.xer);
	// bne cr6,0x8290cc70
	if (!ctx.cr6.eq) goto loc_8290CC70;
	// cmpwi cr6,r25,0
	ctx.cr6.compare<int32_t>(ctx.r25.s32, 0, ctx.xer);
	// beq cr6,0x8290cb30
	if (ctx.cr6.eq) goto loc_8290CB30;
	// cmpwi cr6,r25,2
	ctx.cr6.compare<int32_t>(ctx.r25.s32, 2, ctx.xer);
	// beq cr6,0x8290cb30
	if (ctx.cr6.eq) goto loc_8290CB30;
	// cmpwi cr6,r25,4
	ctx.cr6.compare<int32_t>(ctx.r25.s32, 4, ctx.xer);
	// beq cr6,0x8290cb30
	if (ctx.cr6.eq) goto loc_8290CB30;
	// cmpwi cr6,r25,5
	ctx.cr6.compare<int32_t>(ctx.r25.s32, 5, ctx.xer);
	// beq cr6,0x8290cb30
	if (ctx.cr6.eq) goto loc_8290CB30;
	// addi r11,r1,144
	ctx.r11.s64 = ctx.r1.s64 + 144;
	// li r10,16
	ctx.r10.s64 = 16;
	// mtctr r10
	ctx.ctr.u64 = ctx.r10.u64;
loc_8290CB14:
	// lhz r10,0(r6)
	ctx.r10.u64 = REX_LOAD_U16(ctx.r6.u32 + 0);
	// addi r6,r6,2
	ctx.r6.s64 = ctx.r6.s64 + 2;
	// sth r10,0(r11)
	REX_STORE_U16(ctx.r11.u32 + 0, ctx.r10.u16);
	// addi r11,r11,2
	ctx.r11.s64 = ctx.r11.s64 + 2;
	// bdnz 0x8290cb14
	--ctx.ctr.u64;
	if (ctx.ctr.u32 != 0) goto loc_8290CB14;
	// addi r6,r1,144
	ctx.r6.s64 = ctx.r1.s64 + 144;
	// b 0x8290ce0c
	goto loc_8290CE0C;
loc_8290CB30:
	// rldicl r11,r11,8,56
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u64, 8) & 0xFF;
	// lbz r10,-8(r29)
	ctx.r10.u64 = REX_LOAD_U8(ctx.r29.u32 + -8);
	// neg r9,r6
	ctx.r9.s64 = static_cast<int64_t>(-ctx.r6.u64);
	// lwz r5,152(r31)
	ctx.r5.u64 = REX_LOAD_U32(ctx.r31.u32 + 152);
	// addi r4,r1,148
	ctx.r4.s64 = ctx.r1.s64 + 148;
	// clrlwi r8,r11,26
	ctx.r8.u64 = ctx.r11.u32 & 0x3F;
	// lhz r11,0(r6)
	ctx.r11.u64 = REX_LOAD_U16(ctx.r6.u32 + 0);
	// add r28,r9,r4
	ctx.r28.u64 = ctx.r9.u64 + ctx.r4.u64;
	// rlwinm r4,r8,2,0,29
	ctx.r4.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 2) & 0xFFFFFFFC;
	// rlwinm r26,r8,2,0,29
	ctx.r26.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 2) & 0xFFFFFFFC;
	// clrlwi r10,r10,26
	ctx.r10.u64 = ctx.r10.u32 & 0x3F;
	// add r8,r8,r4
	ctx.r8.u64 = ctx.r8.u64 + ctx.r4.u64;
	// addi r29,r1,144
	ctx.r29.s64 = ctx.r1.s64 + 144;
	// addi r3,r1,146
	ctx.r3.s64 = ctx.r1.s64 + 146;
	// rlwinm r4,r10,2,0,29
	ctx.r4.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 2) & 0xFFFFFFFC;
	// rlwinm r8,r8,2,0,29
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 2) & 0xFFFFFFFC;
	// add r29,r9,r29
	ctx.r29.u64 = ctx.r9.u64 + ctx.r29.u64;
	// add r3,r9,r3
	ctx.r3.u64 = ctx.r9.u64 + ctx.r3.u64;
	// lwzx r9,r26,r22
	ctx.r9.u64 = REX_LOAD_U32(ctx.r26.u32 + ctx.r22.u32);
	// add r4,r10,r4
	ctx.r4.u64 = ctx.r10.u64 + ctx.r4.u64;
	// add r26,r8,r5
	ctx.r26.u64 = ctx.r8.u64 + ctx.r5.u64;
	// rlwinm r8,r4,2,0,29
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r4.u32 | (ctx.r4.u64 << 32), 2) & 0xFFFFFFFC;
	// extsh r27,r11
	ctx.r27.s64 = ctx.r11.s16;
	// add r8,r8,r5
	ctx.r8.u64 = ctx.r8.u64 + ctx.r5.u64;
	// addi r11,r6,6
	ctx.r11.s64 = ctx.r6.s64 + 6;
	// lwz r5,16(r26)
	ctx.r5.u64 = REX_LOAD_U32(ctx.r26.u32 + 16);
	// addi r7,r1,148
	ctx.r7.s64 = ctx.r1.s64 + 148;
	// li r6,3
	ctx.r6.s64 = 3;
	// rlwinm r5,r5,2,0,29
	ctx.r5.u64 = __builtin_rotateleft64(ctx.r5.u32 | (ctx.r5.u64 << 32), 2) & 0xFFFFFFFC;
	// lwz r8,16(r8)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r8.u32 + 16);
	// lwzx r5,r5,r22
	ctx.r5.u64 = REX_LOAD_U32(ctx.r5.u32 + ctx.r22.u32);
	// mullw r8,r5,r8
	ctx.r8.s64 = int64_t(ctx.r5.s32) * int64_t(ctx.r8.s32);
	// mullw r8,r8,r27
	ctx.r8.s64 = int64_t(ctx.r8.s32) * int64_t(ctx.r27.s32);
	// add r8,r8,r30
	ctx.r8.u64 = ctx.r8.u64 + ctx.r30.u64;
	// srawi r8,r8,18
	ctx.xer.ca = (ctx.r8.s32 < 0) & ((ctx.r8.u32 & 0x3FFFF) != 0);
	ctx.r8.s64 = ctx.r8.s32 >> 18;
	// sth r8,144(r1)
	REX_STORE_U16(ctx.r1.u32 + 144, ctx.r8.u16);
loc_8290CBC0:
	// lhz r8,-4(r11)
	ctx.r8.u64 = REX_LOAD_U16(ctx.r11.u32 + -4);
	// addi r6,r6,-1
	ctx.r6.s64 = ctx.r6.s64 + -1;
	// lhz r5,-2(r11)
	ctx.r5.u64 = REX_LOAD_U16(ctx.r11.u32 + -2);
	// lhz r4,0(r11)
	ctx.r4.u64 = REX_LOAD_U16(ctx.r11.u32 + 0);
	// extsh r8,r8
	ctx.r8.s64 = ctx.r8.s16;
	// lhz r27,2(r11)
	ctx.r27.u64 = REX_LOAD_U16(ctx.r11.u32 + 2);
	// extsh r5,r5
	ctx.r5.s64 = ctx.r5.s16;
	// lhz r26,4(r11)
	ctx.r26.u64 = REX_LOAD_U16(ctx.r11.u32 + 4);
	// extsh r4,r4
	ctx.r4.s64 = ctx.r4.s16;
	// extsh r27,r27
	ctx.r27.s64 = ctx.r27.s16;
	// mullw r8,r8,r9
	ctx.r8.s64 = int64_t(ctx.r8.s32) * int64_t(ctx.r9.s32);
	// extsh r26,r26
	ctx.r26.s64 = ctx.r26.s16;
	// mullw r5,r5,r9
	ctx.r5.s64 = int64_t(ctx.r5.s32) * int64_t(ctx.r9.s32);
	// mullw r4,r4,r9
	ctx.r4.s64 = int64_t(ctx.r4.s32) * int64_t(ctx.r9.s32);
	// mullw r27,r27,r9
	ctx.r27.s64 = int64_t(ctx.r27.s32) * int64_t(ctx.r9.s32);
	// mullw r8,r8,r10
	ctx.r8.s64 = int64_t(ctx.r8.s32) * int64_t(ctx.r10.s32);
	// mullw r26,r26,r9
	ctx.r26.s64 = int64_t(ctx.r26.s32) * int64_t(ctx.r9.s32);
	// mullw r5,r5,r10
	ctx.r5.s64 = int64_t(ctx.r5.s32) * int64_t(ctx.r10.s32);
	// mullw r4,r4,r10
	ctx.r4.s64 = int64_t(ctx.r4.s32) * int64_t(ctx.r10.s32);
	// mullw r27,r27,r10
	ctx.r27.s64 = int64_t(ctx.r27.s32) * int64_t(ctx.r10.s32);
	// add r8,r8,r30
	ctx.r8.u64 = ctx.r8.u64 + ctx.r30.u64;
	// mullw r26,r26,r10
	ctx.r26.s64 = int64_t(ctx.r26.s32) * int64_t(ctx.r10.s32);
	// add r5,r5,r30
	ctx.r5.u64 = ctx.r5.u64 + ctx.r30.u64;
	// add r4,r4,r30
	ctx.r4.u64 = ctx.r4.u64 + ctx.r30.u64;
	// srawi r8,r8,18
	ctx.xer.ca = (ctx.r8.s32 < 0) & ((ctx.r8.u32 & 0x3FFFF) != 0);
	ctx.r8.s64 = ctx.r8.s32 >> 18;
	// add r27,r27,r30
	ctx.r27.u64 = ctx.r27.u64 + ctx.r30.u64;
	// srawi r5,r5,18
	ctx.xer.ca = (ctx.r5.s32 < 0) & ((ctx.r5.u32 & 0x3FFFF) != 0);
	ctx.r5.s64 = ctx.r5.s32 >> 18;
	// add r26,r26,r30
	ctx.r26.u64 = ctx.r26.u64 + ctx.r30.u64;
	// srawi r4,r4,18
	ctx.xer.ca = (ctx.r4.s32 < 0) & ((ctx.r4.u32 & 0x3FFFF) != 0);
	ctx.r4.s64 = ctx.r4.s32 >> 18;
	// srawi r27,r27,18
	ctx.xer.ca = (ctx.r27.s32 < 0) & ((ctx.r27.u32 & 0x3FFFF) != 0);
	ctx.r27.s64 = ctx.r27.s32 >> 18;
	// srawi r26,r26,18
	ctx.xer.ca = (ctx.r26.s32 < 0) & ((ctx.r26.u32 & 0x3FFFF) != 0);
	ctx.r26.s64 = ctx.r26.s32 >> 18;
	// sth r8,-2(r7)
	REX_STORE_U16(ctx.r7.u32 + -2, ctx.r8.u16);
	// cmplwi cr6,r6,0
	ctx.cr6.compare<uint32_t>(ctx.r6.u32, 0, ctx.xer);
	// sth r5,0(r7)
	REX_STORE_U16(ctx.r7.u32 + 0, ctx.r5.u16);
	// addi r7,r7,10
	ctx.r7.s64 = ctx.r7.s64 + 10;
	// sthx r4,r11,r29
	REX_STORE_U16(ctx.r11.u32 + ctx.r29.u32, ctx.r4.u16);
	// sthx r27,r11,r3
	REX_STORE_U16(ctx.r11.u32 + ctx.r3.u32, ctx.r27.u16);
	// sthx r26,r11,r28
	REX_STORE_U16(ctx.r11.u32 + ctx.r28.u32, ctx.r26.u16);
	// addi r11,r11,10
	ctx.r11.s64 = ctx.r11.s64 + 10;
	// bne cr6,0x8290cbc0
	if (!ctx.cr6.eq) goto loc_8290CBC0;
	// lhz r11,144(r1)
	ctx.r11.u64 = REX_LOAD_U16(ctx.r1.u32 + 144);
	// addi r6,r1,144
	ctx.r6.s64 = ctx.r1.s64 + 144;
	// sth r11,160(r1)
	REX_STORE_U16(ctx.r1.u32 + 160, ctx.r11.u16);
	// b 0x8290ce0c
	goto loc_8290CE0C;
loc_8290CC70:
	// cmpwi cr6,r25,0
	ctx.cr6.compare<int32_t>(ctx.r25.s32, 0, ctx.xer);
	// beq cr6,0x8290ccb8
	if (ctx.cr6.eq) goto loc_8290CCB8;
	// cmpwi cr6,r25,1
	ctx.cr6.compare<int32_t>(ctx.r25.s32, 1, ctx.xer);
	// beq cr6,0x8290ccb8
	if (ctx.cr6.eq) goto loc_8290CCB8;
	// cmpwi cr6,r25,4
	ctx.cr6.compare<int32_t>(ctx.r25.s32, 4, ctx.xer);
	// beq cr6,0x8290ccb8
	if (ctx.cr6.eq) goto loc_8290CCB8;
	// cmpwi cr6,r25,5
	ctx.cr6.compare<int32_t>(ctx.r25.s32, 5, ctx.xer);
	// beq cr6,0x8290ccb8
	if (ctx.cr6.eq) goto loc_8290CCB8;
	// addi r11,r1,144
	ctx.r11.s64 = ctx.r1.s64 + 144;
	// li r10,16
	ctx.r10.s64 = 16;
	// mtctr r10
	ctx.ctr.u64 = ctx.r10.u64;
loc_8290CC9C:
	// lhz r10,0(r6)
	ctx.r10.u64 = REX_LOAD_U16(ctx.r6.u32 + 0);
	// addi r6,r6,2
	ctx.r6.s64 = ctx.r6.s64 + 2;
	// sth r10,0(r11)
	REX_STORE_U16(ctx.r11.u32 + 0, ctx.r10.u16);
	// addi r11,r11,2
	ctx.r11.s64 = ctx.r11.s64 + 2;
	// bdnz 0x8290cc9c
	--ctx.ctr.u64;
	if (ctx.ctr.u32 != 0) goto loc_8290CC9C;
	// addi r6,r1,160
	ctx.r6.s64 = ctx.r1.s64 + 160;
	// b 0x8290ce0c
	goto loc_8290CE0C;
loc_8290CCB8:
	// rldicl r11,r11,8,56
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u64, 8) & 0xFF;
	// lwz r5,152(r31)
	ctx.r5.u64 = REX_LOAD_U32(ctx.r31.u32 + 152);
	// rlwinm r10,r26,3,0,28
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r26.u32 | (ctx.r26.u64 << 32), 3) & 0xFFFFFFF8;
	// lhz r7,0(r6)
	ctx.r7.u64 = REX_LOAD_U16(ctx.r6.u32 + 0);
	// neg r9,r6
	ctx.r9.s64 = static_cast<int64_t>(-ctx.r6.u64);
	// addi r4,r1,148
	ctx.r4.s64 = ctx.r1.s64 + 148;
	// clrlwi r8,r11,26
	ctx.r8.u64 = ctx.r11.u32 & 0x3F;
	// subf r10,r10,r29
	ctx.r10.u64 = ctx.r29.u64 - ctx.r10.u64;
	// add r28,r9,r4
	ctx.r28.u64 = ctx.r9.u64 + ctx.r4.u64;
	// rlwinm r4,r8,2,0,29
	ctx.r4.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 2) & 0xFFFFFFFC;
	// rlwinm r26,r8,2,0,29
	ctx.r26.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 2) & 0xFFFFFFFC;
	// add r8,r8,r4
	ctx.r8.u64 = ctx.r8.u64 + ctx.r4.u64;
	// lbz r11,0(r10)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r10.u32 + 0);
	// extsh r27,r7
	ctx.r27.s64 = ctx.r7.s16;
	// rlwinm r8,r8,2,0,29
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 2) & 0xFFFFFFFC;
	// clrlwi r10,r11,26
	ctx.r10.u64 = ctx.r11.u32 & 0x3F;
	// add r4,r8,r5
	ctx.r4.u64 = ctx.r8.u64 + ctx.r5.u64;
	// rlwinm r8,r10,2,0,29
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 2) & 0xFFFFFFFC;
	// addi r29,r1,144
	ctx.r29.s64 = ctx.r1.s64 + 144;
	// add r8,r10,r8
	ctx.r8.u64 = ctx.r10.u64 + ctx.r8.u64;
	// addi r3,r1,146
	ctx.r3.s64 = ctx.r1.s64 + 146;
	// rlwinm r8,r8,2,0,29
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 2) & 0xFFFFFFFC;
	// lwz r4,16(r4)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r4.u32 + 16);
	// addi r11,r6,6
	ctx.r11.s64 = ctx.r6.s64 + 6;
	// add r8,r8,r5
	ctx.r8.u64 = ctx.r8.u64 + ctx.r5.u64;
	// rlwinm r4,r4,2,0,29
	ctx.r4.u64 = __builtin_rotateleft64(ctx.r4.u32 | (ctx.r4.u64 << 32), 2) & 0xFFFFFFFC;
	// add r29,r9,r29
	ctx.r29.u64 = ctx.r9.u64 + ctx.r29.u64;
	// add r3,r9,r3
	ctx.r3.u64 = ctx.r9.u64 + ctx.r3.u64;
	// lwzx r9,r26,r22
	ctx.r9.u64 = REX_LOAD_U32(ctx.r26.u32 + ctx.r22.u32);
	// addi r7,r1,148
	ctx.r7.s64 = ctx.r1.s64 + 148;
	// lwz r8,16(r8)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r8.u32 + 16);
	// li r6,3
	ctx.r6.s64 = 3;
	// lwzx r5,r4,r22
	ctx.r5.u64 = REX_LOAD_U32(ctx.r4.u32 + ctx.r22.u32);
	// mullw r8,r5,r8
	ctx.r8.s64 = int64_t(ctx.r5.s32) * int64_t(ctx.r8.s32);
	// mullw r8,r8,r27
	ctx.r8.s64 = int64_t(ctx.r8.s32) * int64_t(ctx.r27.s32);
	// add r8,r8,r30
	ctx.r8.u64 = ctx.r8.u64 + ctx.r30.u64;
	// srawi r8,r8,18
	ctx.xer.ca = (ctx.r8.s32 < 0) & ((ctx.r8.u32 & 0x3FFFF) != 0);
	ctx.r8.s64 = ctx.r8.s32 >> 18;
	// sth r8,144(r1)
	REX_STORE_U16(ctx.r1.u32 + 144, ctx.r8.u16);
loc_8290CD50:
	// lhz r8,-4(r11)
	ctx.r8.u64 = REX_LOAD_U16(ctx.r11.u32 + -4);
	// addi r6,r6,-1
	ctx.r6.s64 = ctx.r6.s64 + -1;
	// lhz r5,-2(r11)
	ctx.r5.u64 = REX_LOAD_U16(ctx.r11.u32 + -2);
	// lhz r4,0(r11)
	ctx.r4.u64 = REX_LOAD_U16(ctx.r11.u32 + 0);
	// extsh r8,r8
	ctx.r8.s64 = ctx.r8.s16;
	// lhz r27,2(r11)
	ctx.r27.u64 = REX_LOAD_U16(ctx.r11.u32 + 2);
	// extsh r5,r5
	ctx.r5.s64 = ctx.r5.s16;
	// lhz r26,4(r11)
	ctx.r26.u64 = REX_LOAD_U16(ctx.r11.u32 + 4);
	// extsh r4,r4
	ctx.r4.s64 = ctx.r4.s16;
	// extsh r27,r27
	ctx.r27.s64 = ctx.r27.s16;
	// mullw r8,r8,r10
	ctx.r8.s64 = int64_t(ctx.r8.s32) * int64_t(ctx.r10.s32);
	// extsh r26,r26
	ctx.r26.s64 = ctx.r26.s16;
	// mullw r5,r5,r10
	ctx.r5.s64 = int64_t(ctx.r5.s32) * int64_t(ctx.r10.s32);
	// mullw r4,r4,r10
	ctx.r4.s64 = int64_t(ctx.r4.s32) * int64_t(ctx.r10.s32);
	// mullw r27,r27,r10
	ctx.r27.s64 = int64_t(ctx.r27.s32) * int64_t(ctx.r10.s32);
	// mullw r8,r8,r9
	ctx.r8.s64 = int64_t(ctx.r8.s32) * int64_t(ctx.r9.s32);
	// mullw r26,r26,r10
	ctx.r26.s64 = int64_t(ctx.r26.s32) * int64_t(ctx.r10.s32);
	// mullw r5,r5,r9
	ctx.r5.s64 = int64_t(ctx.r5.s32) * int64_t(ctx.r9.s32);
	// mullw r4,r4,r9
	ctx.r4.s64 = int64_t(ctx.r4.s32) * int64_t(ctx.r9.s32);
	// mullw r27,r27,r9
	ctx.r27.s64 = int64_t(ctx.r27.s32) * int64_t(ctx.r9.s32);
	// add r8,r8,r30
	ctx.r8.u64 = ctx.r8.u64 + ctx.r30.u64;
	// mullw r26,r26,r9
	ctx.r26.s64 = int64_t(ctx.r26.s32) * int64_t(ctx.r9.s32);
	// add r5,r5,r30
	ctx.r5.u64 = ctx.r5.u64 + ctx.r30.u64;
	// add r4,r4,r30
	ctx.r4.u64 = ctx.r4.u64 + ctx.r30.u64;
	// srawi r8,r8,18
	ctx.xer.ca = (ctx.r8.s32 < 0) & ((ctx.r8.u32 & 0x3FFFF) != 0);
	ctx.r8.s64 = ctx.r8.s32 >> 18;
	// add r27,r27,r30
	ctx.r27.u64 = ctx.r27.u64 + ctx.r30.u64;
	// srawi r5,r5,18
	ctx.xer.ca = (ctx.r5.s32 < 0) & ((ctx.r5.u32 & 0x3FFFF) != 0);
	ctx.r5.s64 = ctx.r5.s32 >> 18;
	// add r26,r26,r30
	ctx.r26.u64 = ctx.r26.u64 + ctx.r30.u64;
	// srawi r4,r4,18
	ctx.xer.ca = (ctx.r4.s32 < 0) & ((ctx.r4.u32 & 0x3FFFF) != 0);
	ctx.r4.s64 = ctx.r4.s32 >> 18;
	// srawi r27,r27,18
	ctx.xer.ca = (ctx.r27.s32 < 0) & ((ctx.r27.u32 & 0x3FFFF) != 0);
	ctx.r27.s64 = ctx.r27.s32 >> 18;
	// srawi r26,r26,18
	ctx.xer.ca = (ctx.r26.s32 < 0) & ((ctx.r26.u32 & 0x3FFFF) != 0);
	ctx.r26.s64 = ctx.r26.s32 >> 18;
	// sth r8,-2(r7)
	REX_STORE_U16(ctx.r7.u32 + -2, ctx.r8.u16);
	// cmplwi cr6,r6,0
	ctx.cr6.compare<uint32_t>(ctx.r6.u32, 0, ctx.xer);
	// sth r5,0(r7)
	REX_STORE_U16(ctx.r7.u32 + 0, ctx.r5.u16);
	// addi r7,r7,10
	ctx.r7.s64 = ctx.r7.s64 + 10;
	// sthx r4,r29,r11
	REX_STORE_U16(ctx.r29.u32 + ctx.r11.u32, ctx.r4.u16);
	// sthx r27,r3,r11
	REX_STORE_U16(ctx.r3.u32 + ctx.r11.u32, ctx.r27.u16);
	// sthx r26,r28,r11
	REX_STORE_U16(ctx.r28.u32 + ctx.r11.u32, ctx.r26.u16);
	// addi r11,r11,10
	ctx.r11.s64 = ctx.r11.s64 + 10;
	// bne cr6,0x8290cd50
	if (!ctx.cr6.eq) goto loc_8290CD50;
	// lhz r11,144(r1)
	ctx.r11.u64 = REX_LOAD_U16(ctx.r1.u32 + 144);
	// addi r6,r1,160
	ctx.r6.s64 = ctx.r1.s64 + 160;
	// sth r11,160(r1)
	REX_STORE_U16(ctx.r1.u32 + 160, ctx.r11.u16);
	// b 0x8290ce0c
	goto loc_8290CE0C;
loc_8290CE00:
	// cmplw cr6,r6,r24
	ctx.cr6.compare<uint32_t>(ctx.r6.u32, ctx.r24.u32, ctx.xer);
	// bne cr6,0x8290ce0c
	if (!ctx.cr6.eq) goto loc_8290CE0C;
	// addi r6,r6,16
	ctx.r6.s64 = ctx.r6.s64 + 16;
loc_8290CE0C:
	// lwz r11,972(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 972);
	// li r10,-128
	ctx.r10.s64 = -128;
	// stw r6,200(r1)
	REX_STORE_U32(ctx.r1.u32 + 200, ctx.r6.u32);
	// addi r11,r11,-128
	ctx.r11.s64 = ctx.r11.s64 + -128;
	// stw r11,176(r1)
	REX_STORE_U32(ctx.r1.u32 + 176, ctx.r11.u32);
	// dcbt r10,r11
	// lwz r11,176(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 176);
	// dcbzl r0,r11
	ea = (ctx.r11.u32) & ~127;
	memset((void*)REX_RAW_ADDR(ea), 0, 128);
	// lwz r3,176(r1)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r1.u32 + 176);
	// lwz r10,200(r1)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r1.u32 + 200);
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// stw r3,972(r31)
	REX_STORE_U32(ctx.r31.u32 + 972, ctx.r3.u32);
	// beq cr6,0x8290cfdc
	if (ctx.cr6.eq) goto loc_8290CFDC;
	// lhz r9,0(r10)
	ctx.r9.u64 = REX_LOAD_U16(ctx.r10.u32 + 0);
	// cmpwi cr6,r21,1
	ctx.cr6.compare<int32_t>(ctx.r21.s32, 1, ctx.xer);
	// lhz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U16(ctx.r3.u32 + 0);
	// add r11,r11,r9
	ctx.r11.u64 = ctx.r11.u64 + ctx.r9.u64;
	// extsh r9,r11
	ctx.r9.s64 = ctx.r11.s16;
	// lwz r11,84(r1)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r1.u32 + 84);
	// sth r9,0(r3)
	REX_STORE_U16(ctx.r3.u32 + 0, ctx.r9.u16);
	// sth r9,0(r11)
	REX_STORE_U16(ctx.r11.u32 + 0, ctx.r9.u16);
	// sth r9,16(r11)
	REX_STORE_U16(ctx.r11.u32 + 16, ctx.r9.u16);
	// bne cr6,0x8290cf14
	if (!ctx.cr6.eq) goto loc_8290CF14;
	// lhz r9,2(r10)
	ctx.r9.u64 = REX_LOAD_U16(ctx.r10.u32 + 2);
	// lhz r8,2(r3)
	ctx.r8.u64 = REX_LOAD_U16(ctx.r3.u32 + 2);
	// add r9,r9,r8
	ctx.r9.u64 = ctx.r9.u64 + ctx.r8.u64;
	// extsh r9,r9
	ctx.r9.s64 = ctx.r9.s16;
	// sth r9,2(r3)
	REX_STORE_U16(ctx.r3.u32 + 2, ctx.r9.u16);
	// sth r9,2(r11)
	REX_STORE_U16(ctx.r11.u32 + 2, ctx.r9.u16);
	// lhz r9,4(r10)
	ctx.r9.u64 = REX_LOAD_U16(ctx.r10.u32 + 4);
	// lhz r8,4(r3)
	ctx.r8.u64 = REX_LOAD_U16(ctx.r3.u32 + 4);
	// add r9,r9,r8
	ctx.r9.u64 = ctx.r9.u64 + ctx.r8.u64;
	// extsh r9,r9
	ctx.r9.s64 = ctx.r9.s16;
	// sth r9,4(r3)
	REX_STORE_U16(ctx.r3.u32 + 4, ctx.r9.u16);
	// sth r9,4(r11)
	REX_STORE_U16(ctx.r11.u32 + 4, ctx.r9.u16);
	// lhz r9,6(r10)
	ctx.r9.u64 = REX_LOAD_U16(ctx.r10.u32 + 6);
	// lhz r8,6(r3)
	ctx.r8.u64 = REX_LOAD_U16(ctx.r3.u32 + 6);
	// add r9,r9,r8
	ctx.r9.u64 = ctx.r9.u64 + ctx.r8.u64;
	// extsh r9,r9
	ctx.r9.s64 = ctx.r9.s16;
	// sth r9,6(r3)
	REX_STORE_U16(ctx.r3.u32 + 6, ctx.r9.u16);
	// sth r9,6(r11)
	REX_STORE_U16(ctx.r11.u32 + 6, ctx.r9.u16);
	// lhz r9,8(r10)
	ctx.r9.u64 = REX_LOAD_U16(ctx.r10.u32 + 8);
	// lhz r8,8(r3)
	ctx.r8.u64 = REX_LOAD_U16(ctx.r3.u32 + 8);
	// add r9,r9,r8
	ctx.r9.u64 = ctx.r9.u64 + ctx.r8.u64;
	// extsh r9,r9
	ctx.r9.s64 = ctx.r9.s16;
	// sth r9,8(r3)
	REX_STORE_U16(ctx.r3.u32 + 8, ctx.r9.u16);
	// sth r9,8(r11)
	REX_STORE_U16(ctx.r11.u32 + 8, ctx.r9.u16);
	// lhz r9,10(r10)
	ctx.r9.u64 = REX_LOAD_U16(ctx.r10.u32 + 10);
	// lhz r8,10(r3)
	ctx.r8.u64 = REX_LOAD_U16(ctx.r3.u32 + 10);
	// add r9,r9,r8
	ctx.r9.u64 = ctx.r9.u64 + ctx.r8.u64;
	// extsh r9,r9
	ctx.r9.s64 = ctx.r9.s16;
	// sth r9,10(r3)
	REX_STORE_U16(ctx.r3.u32 + 10, ctx.r9.u16);
	// sth r9,10(r11)
	REX_STORE_U16(ctx.r11.u32 + 10, ctx.r9.u16);
	// lhz r9,12(r10)
	ctx.r9.u64 = REX_LOAD_U16(ctx.r10.u32 + 12);
	// lhz r8,12(r3)
	ctx.r8.u64 = REX_LOAD_U16(ctx.r3.u32 + 12);
	// add r9,r9,r8
	ctx.r9.u64 = ctx.r9.u64 + ctx.r8.u64;
	// extsh r9,r9
	ctx.r9.s64 = ctx.r9.s16;
	// sth r9,12(r3)
	REX_STORE_U16(ctx.r3.u32 + 12, ctx.r9.u16);
	// sth r9,12(r11)
	REX_STORE_U16(ctx.r11.u32 + 12, ctx.r9.u16);
	// lhz r10,14(r10)
	ctx.r10.u64 = REX_LOAD_U16(ctx.r10.u32 + 14);
	// lhz r9,14(r3)
	ctx.r9.u64 = REX_LOAD_U16(ctx.r3.u32 + 14);
	// add r10,r10,r9
	ctx.r10.u64 = ctx.r10.u64 + ctx.r9.u64;
	// extsh r10,r10
	ctx.r10.s64 = ctx.r10.s16;
	// sth r10,14(r3)
	REX_STORE_U16(ctx.r3.u32 + 14, ctx.r10.u16);
	// sth r10,14(r11)
	REX_STORE_U16(ctx.r11.u32 + 14, ctx.r10.u16);
	// b 0x8290d004
	goto loc_8290D004;
loc_8290CF14:
	// cmpwi cr6,r21,8
	ctx.cr6.compare<int32_t>(ctx.r21.s32, 8, ctx.xer);
	// bne cr6,0x8290cfec
	if (!ctx.cr6.eq) goto loc_8290CFEC;
	// lhz r9,2(r3)
	ctx.r9.u64 = REX_LOAD_U16(ctx.r3.u32 + 2);
	// sth r9,2(r11)
	REX_STORE_U16(ctx.r11.u32 + 2, ctx.r9.u16);
	// lwz r9,4(r3)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r3.u32 + 4);
	// stw r9,4(r11)
	REX_STORE_U32(ctx.r11.u32 + 4, ctx.r9.u32);
	// ld r9,8(r3)
	ctx.r9.u64 = REX_LOAD_U64(ctx.r3.u32 + 8);
	// std r9,8(r11)
	REX_STORE_U64(ctx.r11.u32 + 8, ctx.r9.u64);
	// lhz r9,2(r10)
	ctx.r9.u64 = REX_LOAD_U16(ctx.r10.u32 + 2);
	// lhz r8,16(r3)
	ctx.r8.u64 = REX_LOAD_U16(ctx.r3.u32 + 16);
	// add r9,r9,r8
	ctx.r9.u64 = ctx.r9.u64 + ctx.r8.u64;
	// extsh r9,r9
	ctx.r9.s64 = ctx.r9.s16;
	// sth r9,16(r3)
	REX_STORE_U16(ctx.r3.u32 + 16, ctx.r9.u16);
	// sth r9,18(r11)
	REX_STORE_U16(ctx.r11.u32 + 18, ctx.r9.u16);
	// lhz r9,4(r10)
	ctx.r9.u64 = REX_LOAD_U16(ctx.r10.u32 + 4);
	// lhz r8,32(r3)
	ctx.r8.u64 = REX_LOAD_U16(ctx.r3.u32 + 32);
	// add r9,r9,r8
	ctx.r9.u64 = ctx.r9.u64 + ctx.r8.u64;
	// extsh r9,r9
	ctx.r9.s64 = ctx.r9.s16;
	// sth r9,32(r3)
	REX_STORE_U16(ctx.r3.u32 + 32, ctx.r9.u16);
	// sth r9,20(r11)
	REX_STORE_U16(ctx.r11.u32 + 20, ctx.r9.u16);
	// lhz r9,6(r10)
	ctx.r9.u64 = REX_LOAD_U16(ctx.r10.u32 + 6);
	// lhz r8,48(r3)
	ctx.r8.u64 = REX_LOAD_U16(ctx.r3.u32 + 48);
	// add r9,r9,r8
	ctx.r9.u64 = ctx.r9.u64 + ctx.r8.u64;
	// extsh r9,r9
	ctx.r9.s64 = ctx.r9.s16;
	// sth r9,48(r3)
	REX_STORE_U16(ctx.r3.u32 + 48, ctx.r9.u16);
	// sth r9,22(r11)
	REX_STORE_U16(ctx.r11.u32 + 22, ctx.r9.u16);
	// lhz r9,8(r10)
	ctx.r9.u64 = REX_LOAD_U16(ctx.r10.u32 + 8);
	// lhz r8,64(r3)
	ctx.r8.u64 = REX_LOAD_U16(ctx.r3.u32 + 64);
	// add r9,r9,r8
	ctx.r9.u64 = ctx.r9.u64 + ctx.r8.u64;
	// extsh r9,r9
	ctx.r9.s64 = ctx.r9.s16;
	// sth r9,64(r3)
	REX_STORE_U16(ctx.r3.u32 + 64, ctx.r9.u16);
	// sth r9,24(r11)
	REX_STORE_U16(ctx.r11.u32 + 24, ctx.r9.u16);
	// lhz r9,10(r10)
	ctx.r9.u64 = REX_LOAD_U16(ctx.r10.u32 + 10);
	// lhz r8,80(r3)
	ctx.r8.u64 = REX_LOAD_U16(ctx.r3.u32 + 80);
	// add r9,r9,r8
	ctx.r9.u64 = ctx.r9.u64 + ctx.r8.u64;
	// extsh r9,r9
	ctx.r9.s64 = ctx.r9.s16;
	// sth r9,80(r3)
	REX_STORE_U16(ctx.r3.u32 + 80, ctx.r9.u16);
	// sth r9,26(r11)
	REX_STORE_U16(ctx.r11.u32 + 26, ctx.r9.u16);
	// lhz r9,12(r10)
	ctx.r9.u64 = REX_LOAD_U16(ctx.r10.u32 + 12);
	// lhz r8,96(r3)
	ctx.r8.u64 = REX_LOAD_U16(ctx.r3.u32 + 96);
	// add r9,r9,r8
	ctx.r9.u64 = ctx.r9.u64 + ctx.r8.u64;
	// extsh r9,r9
	ctx.r9.s64 = ctx.r9.s16;
	// sth r9,96(r3)
	REX_STORE_U16(ctx.r3.u32 + 96, ctx.r9.u16);
	// sth r9,28(r11)
	REX_STORE_U16(ctx.r11.u32 + 28, ctx.r9.u16);
	// lhz r10,14(r10)
	ctx.r10.u64 = REX_LOAD_U16(ctx.r10.u32 + 14);
	// lhz r9,112(r3)
	ctx.r9.u64 = REX_LOAD_U16(ctx.r3.u32 + 112);
	// add r10,r10,r9
	ctx.r10.u64 = ctx.r10.u64 + ctx.r9.u64;
	// extsh r10,r10
	ctx.r10.s64 = ctx.r10.s16;
	// sth r10,112(r3)
	REX_STORE_U16(ctx.r3.u32 + 112, ctx.r10.u16);
	// b 0x8290d038
	goto loc_8290D038;
loc_8290CFDC:
	// lhz r10,0(r3)
	ctx.r10.u64 = REX_LOAD_U16(ctx.r3.u32 + 0);
	// lwz r11,84(r1)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r1.u32 + 84);
	// sth r10,0(r11)
	REX_STORE_U16(ctx.r11.u32 + 0, ctx.r10.u16);
	// sth r10,16(r11)
	REX_STORE_U16(ctx.r11.u32 + 16, ctx.r10.u16);
loc_8290CFEC:
	// lhz r10,2(r3)
	ctx.r10.u64 = REX_LOAD_U16(ctx.r3.u32 + 2);
	// sth r10,2(r11)
	REX_STORE_U16(ctx.r11.u32 + 2, ctx.r10.u16);
	// lwz r10,4(r3)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r3.u32 + 4);
	// stw r10,4(r11)
	REX_STORE_U32(ctx.r11.u32 + 4, ctx.r10.u32);
	// ld r10,8(r3)
	ctx.r10.u64 = REX_LOAD_U64(ctx.r3.u32 + 8);
	// std r10,8(r11)
	REX_STORE_U64(ctx.r11.u32 + 8, ctx.r10.u64);
loc_8290D004:
	// lhz r10,16(r3)
	ctx.r10.u64 = REX_LOAD_U16(ctx.r3.u32 + 16);
	// sth r10,18(r11)
	REX_STORE_U16(ctx.r11.u32 + 18, ctx.r10.u16);
	// lhz r10,32(r3)
	ctx.r10.u64 = REX_LOAD_U16(ctx.r3.u32 + 32);
	// sth r10,20(r11)
	REX_STORE_U16(ctx.r11.u32 + 20, ctx.r10.u16);
	// lhz r10,48(r3)
	ctx.r10.u64 = REX_LOAD_U16(ctx.r3.u32 + 48);
	// sth r10,22(r11)
	REX_STORE_U16(ctx.r11.u32 + 22, ctx.r10.u16);
	// lhz r10,64(r3)
	ctx.r10.u64 = REX_LOAD_U16(ctx.r3.u32 + 64);
	// sth r10,24(r11)
	REX_STORE_U16(ctx.r11.u32 + 24, ctx.r10.u16);
	// lhz r10,80(r3)
	ctx.r10.u64 = REX_LOAD_U16(ctx.r3.u32 + 80);
	// sth r10,26(r11)
	REX_STORE_U16(ctx.r11.u32 + 26, ctx.r10.u16);
	// lhz r10,96(r3)
	ctx.r10.u64 = REX_LOAD_U16(ctx.r3.u32 + 96);
	// sth r10,28(r11)
	REX_STORE_U16(ctx.r11.u32 + 28, ctx.r10.u16);
	// lhz r10,112(r3)
	ctx.r10.u64 = REX_LOAD_U16(ctx.r3.u32 + 112);
loc_8290D038:
	// sth r10,30(r11)
	REX_STORE_U16(ctx.r11.u32 + 30, ctx.r10.u16);
	// lwz r11,196(r1)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r1.u32 + 196);
	// lwz r10,156(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 156);
	// lwz r29,112(r1)
	ctx.r29.u64 = REX_LOAD_U32(ctx.r1.u32 + 112);
	// rlwinm r11,r11,6,18,25
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 6) & 0x3FC0;
	// lwz r4,176(r31)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r31.u32 + 176);
	// add r5,r11,r10
	ctx.r5.u64 = ctx.r11.u64 + ctx.r10.u64;
	// lwz r7,188(r1)
	ctx.r7.u64 = REX_LOAD_U32(ctx.r1.u32 + 188);
	// srawi r9,r29,2
	ctx.xer.ca = (ctx.r29.s32 < 0) & ((ctx.r29.u32 & 0x3) != 0);
	ctx.r9.s64 = ctx.r29.s32 >> 2;
	// lis r11,-32101
	ctx.r11.s64 = -2103771136;
	// addi r9,r9,37
	ctx.r9.s64 = ctx.r9.s64 + 37;
	// rlwinm r10,r9,1,0,30
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 1) & 0xFFFFFFFE;
	// lwz r9,420(r11)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r11.u32 + 420);
	// lis r11,-32101
	ctx.r11.s64 = -2103771136;
	// lhzx r8,r10,r31
	ctx.r8.u64 = REX_LOAD_U16(ctx.r10.u32 + ctx.r31.u32);
	// lwz r6,408(r11)
	ctx.r6.u64 = REX_LOAD_U32(ctx.r11.u32 + 408);
	// bl 0x82560160
	ctx.lr = 0x8290D07C;
	sub_82560160(ctx, base);
	// addi r25,r29,1
	ctx.r25.s64 = ctx.r29.s64 + 1;
	// cmpwi cr6,r25,6
	ctx.cr6.compare<int32_t>(ctx.r25.s32, 6, ctx.xer);
	// stw r25,112(r1)
	REX_STORE_U32(ctx.r1.u32 + 112, ctx.r25.u32);
	// blt cr6,0x8290c750
	if (ctx.cr6.lt) goto loc_8290C750;
	// lwz r9,128(r1)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r1.u32 + 128);
	// lwz r8,88(r1)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r1.u32 + 88);
	// lwz r10,0(r9)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r9.u32 + 0);
	// addi r9,r9,4
	ctx.r9.s64 = ctx.r9.s64 + 4;
	// rlwinm r11,r10,16,22,31
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 16) & 0x3FF;
	// clrlwi r20,r10,16
	ctx.r20.u64 = ctx.r10.u32 & 0xFFFF;
	// lwz r10,132(r1)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r1.u32 + 132);
	// cmplw cr6,r8,r11
	ctx.cr6.compare<uint32_t>(ctx.r8.u32, ctx.r11.u32, ctx.xer);
	// addi r10,r10,-1
	ctx.r10.s64 = ctx.r10.s64 + -1;
	// stw r9,128(r1)
	REX_STORE_U32(ctx.r1.u32 + 128, ctx.r9.u32);
	// lwz r9,124(r1)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r1.u32 + 124);
	// stw r11,96(r1)
	REX_STORE_U32(ctx.r1.u32 + 96, ctx.r11.u32);
	// stw r10,132(r1)
	REX_STORE_U32(ctx.r1.u32 + 132, ctx.r10.u32);
	// bne cr6,0x8290d12c
	if (!ctx.cr6.eq) goto loc_8290D12C;
	// lwz r29,80(r1)
	ctx.r29.u64 = REX_LOAD_U32(ctx.r1.u32 + 80);
	// lwz r10,108(r1)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r1.u32 + 108);
	// b 0x8290c708
	goto loc_8290C708;
loc_8290D0D0:
	// cmplw cr6,r8,r11
	ctx.cr6.compare<uint32_t>(ctx.r8.u32, ctx.r11.u32, ctx.xer);
	// bne cr6,0x8290d12c
	if (!ctx.cr6.eq) goto loc_8290D12C;
	// lhz r6,270(r31)
	ctx.r6.u64 = REX_LOAD_U16(ctx.r31.u32 + 270);
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// lwz r7,128(r31)
	ctx.r7.u64 = REX_LOAD_U32(ctx.r31.u32 + 128);
	// addi r29,r29,8
	ctx.r29.s64 = ctx.r29.s64 + 8;
	// addi r4,r6,2
	ctx.r4.s64 = ctx.r6.s64 + 2;
	// lwz r5,132(r31)
	ctx.r5.u64 = REX_LOAD_U32(ctx.r31.u32 + 132);
	// addi r3,r7,2
	ctx.r3.s64 = ctx.r7.s64 + 2;
	// lwz r6,260(r31)
	ctx.r6.u64 = REX_LOAD_U32(ctx.r31.u32 + 260);
	// lwz r7,264(r31)
	ctx.r7.u64 = REX_LOAD_U32(ctx.r31.u32 + 264);
	// addi r5,r5,1
	ctx.r5.s64 = ctx.r5.s64 + 1;
	// addi r6,r6,16
	ctx.r6.s64 = ctx.r6.s64 + 16;
	// stw r10,108(r1)
	REX_STORE_U32(ctx.r1.u32 + 108, ctx.r10.u32);
	// addi r7,r7,8
	ctx.r7.s64 = ctx.r7.s64 + 8;
	// stw r29,80(r1)
	REX_STORE_U32(ctx.r1.u32 + 80, ctx.r29.u32);
	// cmplw cr6,r10,r9
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, ctx.r9.u32, ctx.xer);
	// sth r4,270(r31)
	REX_STORE_U16(ctx.r31.u32 + 270, ctx.r4.u16);
	// stw r3,128(r31)
	REX_STORE_U32(ctx.r31.u32 + 128, ctx.r3.u32);
	// stw r5,132(r31)
	REX_STORE_U32(ctx.r31.u32 + 132, ctx.r5.u32);
	// stw r6,260(r31)
	REX_STORE_U32(ctx.r31.u32 + 260, ctx.r6.u32);
	// stw r7,264(r31)
	REX_STORE_U32(ctx.r31.u32 + 264, ctx.r7.u32);
	// blt cr6,0x8290c708
	if (ctx.cr6.lt) goto loc_8290C708;
loc_8290D12C:
	// lwz r6,116(r1)
	ctx.r6.u64 = REX_LOAD_U32(ctx.r1.u32 + 116);
	// rlwinm r10,r9,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 2) & 0xFFFFFFFC;
	// lhz r7,268(r31)
	ctx.r7.u64 = REX_LOAD_U16(ctx.r31.u32 + 268);
	// addi r8,r8,1
	ctx.r8.s64 = ctx.r8.s64 + 1;
	// add r5,r9,r6
	ctx.r5.u64 = ctx.r9.u64 + ctx.r6.u64;
	// lwz r6,100(r1)
	ctx.r6.u64 = REX_LOAD_U32(ctx.r1.u32 + 100);
	// addi r3,r7,2
	ctx.r3.s64 = ctx.r7.s64 + 2;
	// add r4,r10,r6
	ctx.r4.u64 = ctx.r10.u64 + ctx.r6.u64;
	// lwz r10,204(r1)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r1.u32 + 204);
	// rlwinm r6,r9,3,0,28
	ctx.r6.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 3) & 0xFFFFFFF8;
	// rlwinm r7,r10,4,0,27
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 4) & 0xFFFFFFF0;
	// stw r8,88(r1)
	REX_STORE_U32(ctx.r1.u32 + 88, ctx.r8.u32);
	// rlwinm r10,r10,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 2) & 0xFFFFFFFC;
	// stw r5,116(r1)
	REX_STORE_U32(ctx.r1.u32 + 116, ctx.r5.u32);
	// stw r5,132(r31)
	REX_STORE_U32(ctx.r31.u32 + 132, ctx.r5.u32);
	// li r27,0
	ctx.r27.s64 = 0;
	// stw r4,100(r1)
	REX_STORE_U32(ctx.r1.u32 + 100, ctx.r4.u32);
	// stw r4,128(r31)
	REX_STORE_U32(ctx.r31.u32 + 128, ctx.r4.u32);
	// lwz r4,104(r1)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r1.u32 + 104);
	// sth r3,268(r31)
	REX_STORE_U16(ctx.r31.u32 + 268, ctx.r3.u16);
	// add r29,r6,r4
	ctx.r29.u64 = ctx.r6.u64 + ctx.r4.u64;
	// lwz r6,120(r1)
	ctx.r6.u64 = REX_LOAD_U32(ctx.r1.u32 + 120);
	// add r7,r7,r6
	ctx.r7.u64 = ctx.r7.u64 + ctx.r6.u64;
	// lwz r6,92(r1)
	ctx.r6.u64 = REX_LOAD_U32(ctx.r1.u32 + 92);
	// add r6,r10,r6
	ctx.r6.u64 = ctx.r10.u64 + ctx.r6.u64;
	// lwz r10,180(r1)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r1.u32 + 180);
	// stw r29,104(r1)
	REX_STORE_U32(ctx.r1.u32 + 104, ctx.r29.u32);
	// stw r29,80(r1)
	REX_STORE_U32(ctx.r1.u32 + 80, ctx.r29.u32);
	// cmplw cr6,r8,r10
	ctx.cr6.compare<uint32_t>(ctx.r8.u32, ctx.r10.u32, ctx.xer);
	// stw r7,120(r1)
	REX_STORE_U32(ctx.r1.u32 + 120, ctx.r7.u32);
	// stw r6,92(r1)
	REX_STORE_U32(ctx.r1.u32 + 92, ctx.r6.u32);
	// blt cr6,0x8290c6d4
	if (ctx.cr6.lt) goto loc_8290C6D4;
	// lwz r28,184(r1)
	ctx.r28.u64 = REX_LOAD_U32(ctx.r1.u32 + 184);
loc_8290D1B0:
	// lis r11,-32101
	ctx.r11.s64 = -2103771136;
	// addi r4,r1,208
	ctx.r4.s64 = ctx.r1.s64 + 208;
	// mr r3,r28
	ctx.r3.u64 = ctx.r28.u64;
	// lwz r31,416(r11)
	ctx.r31.u64 = REX_LOAD_U32(ctx.r11.u32 + 416);
	// bl 0x8290a790
	ctx.lr = 0x8290D1C4;
	sub_8290A790(ctx, base);
	// mr r8,r27
	ctx.r8.u64 = ctx.r27.u64;
	// addi r10,r31,8
	ctx.r10.s64 = ctx.r31.s64 + 8;
	// addi r11,r1,1220
	ctx.r11.s64 = ctx.r1.s64 + 1220;
	// lis r7,-32105
	ctx.r7.s64 = -2104033280;
loc_8290D1D4:
	// lwz r9,-8(r10)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r10.u32 + -8);
	// lwz r6,-4(r11)
	ctx.r6.u64 = REX_LOAD_U32(ctx.r11.u32 + -4);
	// cmplw cr6,r9,r6
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, ctx.r6.u32, ctx.xer);
	// bne cr6,0x8290d214
	if (!ctx.cr6.eq) goto loc_8290D214;
	// lwz r9,-4(r10)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r10.u32 + -4);
	// lwz r6,0(r11)
	ctx.r6.u64 = REX_LOAD_U32(ctx.r11.u32 + 0);
	// cmplw cr6,r9,r6
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, ctx.r6.u32, ctx.xer);
	// bne cr6,0x8290d214
	if (!ctx.cr6.eq) goto loc_8290D214;
	// lwz r9,0(r10)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r10.u32 + 0);
	// lwz r6,4(r11)
	ctx.r6.u64 = REX_LOAD_U32(ctx.r11.u32 + 4);
	// cmplw cr6,r9,r6
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, ctx.r6.u32, ctx.xer);
	// bne cr6,0x8290d214
	if (!ctx.cr6.eq) goto loc_8290D214;
	// lwz r9,4(r10)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r10.u32 + 4);
	// lwz r6,8(r11)
	ctx.r6.u64 = REX_LOAD_U32(ctx.r11.u32 + 8);
	// cmplw cr6,r9,r6
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, ctx.r6.u32, ctx.xer);
	// beq cr6,0x8290d218
	if (ctx.cr6.eq) goto loc_8290D218;
loc_8290D214:
	// stw r8,29216(r7)
	REX_STORE_U32(ctx.r7.u32 + 29216, ctx.r8.u32);
loc_8290D218:
	// lwz r9,8(r10)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r10.u32 + 8);
	// lwz r6,-20(r11)
	ctx.r6.u64 = REX_LOAD_U32(ctx.r11.u32 + -20);
	// cmplw cr6,r9,r6
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, ctx.r6.u32, ctx.xer);
	// bne cr6,0x8290d258
	if (!ctx.cr6.eq) goto loc_8290D258;
	// lwz r9,12(r10)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r10.u32 + 12);
	// lwz r6,-16(r11)
	ctx.r6.u64 = REX_LOAD_U32(ctx.r11.u32 + -16);
	// cmplw cr6,r9,r6
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, ctx.r6.u32, ctx.xer);
	// bne cr6,0x8290d258
	if (!ctx.cr6.eq) goto loc_8290D258;
	// lwz r9,16(r10)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r10.u32 + 16);
	// lwz r6,-12(r11)
	ctx.r6.u64 = REX_LOAD_U32(ctx.r11.u32 + -12);
	// cmplw cr6,r9,r6
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, ctx.r6.u32, ctx.xer);
	// bne cr6,0x8290d258
	if (!ctx.cr6.eq) goto loc_8290D258;
	// lwz r9,20(r10)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r10.u32 + 20);
	// lwz r6,-8(r11)
	ctx.r6.u64 = REX_LOAD_U32(ctx.r11.u32 + -8);
	// cmplw cr6,r9,r6
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, ctx.r6.u32, ctx.xer);
	// beq cr6,0x8290d260
	if (ctx.cr6.eq) goto loc_8290D260;
loc_8290D258:
	// addi r9,r8,1
	ctx.r9.s64 = ctx.r8.s64 + 1;
	// stw r9,29216(r7)
	REX_STORE_U32(ctx.r7.u32 + 29216, ctx.r9.u32);
loc_8290D260:
	// lwz r9,24(r10)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r10.u32 + 24);
	// lwz r6,-36(r11)
	ctx.r6.u64 = REX_LOAD_U32(ctx.r11.u32 + -36);
	// cmplw cr6,r9,r6
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, ctx.r6.u32, ctx.xer);
	// bne cr6,0x8290d2a0
	if (!ctx.cr6.eq) goto loc_8290D2A0;
	// lwz r9,28(r10)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r10.u32 + 28);
	// lwz r6,-32(r11)
	ctx.r6.u64 = REX_LOAD_U32(ctx.r11.u32 + -32);
	// cmplw cr6,r9,r6
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, ctx.r6.u32, ctx.xer);
	// bne cr6,0x8290d2a0
	if (!ctx.cr6.eq) goto loc_8290D2A0;
	// lwz r9,32(r10)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r10.u32 + 32);
	// lwz r6,-28(r11)
	ctx.r6.u64 = REX_LOAD_U32(ctx.r11.u32 + -28);
	// cmplw cr6,r9,r6
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, ctx.r6.u32, ctx.xer);
	// bne cr6,0x8290d2a0
	if (!ctx.cr6.eq) goto loc_8290D2A0;
	// lwz r9,36(r10)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r10.u32 + 36);
	// lwz r6,-24(r11)
	ctx.r6.u64 = REX_LOAD_U32(ctx.r11.u32 + -24);
	// cmplw cr6,r9,r6
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, ctx.r6.u32, ctx.xer);
	// beq cr6,0x8290d2a8
	if (ctx.cr6.eq) goto loc_8290D2A8;
loc_8290D2A0:
	// addi r9,r8,2
	ctx.r9.s64 = ctx.r8.s64 + 2;
	// stw r9,29216(r7)
	REX_STORE_U32(ctx.r7.u32 + 29216, ctx.r9.u32);
loc_8290D2A8:
	// addi r8,r8,3
	ctx.r8.s64 = ctx.r8.s64 + 3;
	// addi r11,r11,-48
	ctx.r11.s64 = ctx.r11.s64 + -48;
	// addi r10,r10,48
	ctx.r10.s64 = ctx.r10.s64 + 48;
	// cmpwi cr6,r8,9
	ctx.cr6.compare<int32_t>(ctx.r8.s32, 9, ctx.xer);
	// blt cr6,0x8290d1d4
	if (ctx.cr6.lt) goto loc_8290D1D4;
	// lwz r3,192(r1)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r1.u32 + 192);
	// addi r1,r1,1872
	ctx.r1.s64 = ctx.r1.s64 + 1872;
	// b 0x8279e44c
	__restgprlr_17(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_8290D400) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x8279e3f0
	ctx.lr = 0x8290D408;
	__savegprlr_14(ctx, base);
	// stwu r1,-304(r1)
	ea = -304 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r27,r3
	ctx.r27.u64 = ctx.r3.u64;
	// mr r18,r4
	ctx.r18.u64 = ctx.r4.u64;
	// li r14,0
	ctx.r14.s64 = 0;
	// mr r16,r18
	ctx.r16.u64 = ctx.r18.u64;
	// lwz r11,2896(r27)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r27.u32 + 2896);
	// lwz r10,2864(r27)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r27.u32 + 2864);
	// addi r11,r11,718
	ctx.r11.s64 = ctx.r11.s64 + 718;
	// stw r27,324(r1)
	REX_STORE_U32(ctx.r1.u32 + 324, ctx.r27.u32);
	// stw r16,136(r1)
	REX_STORE_U32(ctx.r1.u32 + 136, ctx.r16.u32);
	// rlwinm r11,r11,2,0,29
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r11,r11,r27
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + ctx.r27.u32);
	// stw r11,0(r10)
	REX_STORE_U32(ctx.r10.u32 + 0, ctx.r11.u32);
	// lwz r11,2896(r27)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r27.u32 + 2896);
	// lwz r10,2868(r27)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r27.u32 + 2868);
	// addi r11,r11,721
	ctx.r11.s64 = ctx.r11.s64 + 721;
	// rlwinm r11,r11,2,0,29
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r11,r11,r27
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + ctx.r27.u32);
	// stw r11,0(r10)
	REX_STORE_U32(ctx.r10.u32 + 0, ctx.r11.u32);
	// lwz r11,2072(r27)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r27.u32 + 2072);
	// lwz r9,3916(r27)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r27.u32 + 3916);
	// rlwinm r10,r11,3,0,28
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 3) & 0xFFFFFFF8;
	// addi r11,r11,261
	ctx.r11.s64 = ctx.r11.s64 + 261;
	// add r10,r10,r27
	ctx.r10.u64 = ctx.r10.u64 + ctx.r27.u64;
	// rlwinm r11,r11,3,0,28
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 3) & 0xFFFFFFF8;
	// cmpwi cr6,r9,3
	ctx.cr6.compare<int32_t>(ctx.r9.s32, 3, ctx.xer);
	// lwz r10,2084(r10)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r10.u32 + 2084);
	// stw r10,2076(r27)
	REX_STORE_U32(ctx.r27.u32 + 2076, ctx.r10.u32);
	// lwzx r11,r11,r27
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + ctx.r27.u32);
	// stw r11,2080(r27)
	REX_STORE_U32(ctx.r27.u32 + 2080, ctx.r11.u32);
	// li r11,1
	ctx.r11.s64 = 1;
	// bne cr6,0x8290d490
	if (!ctx.cr6.eq) goto loc_8290D490;
	// stw r14,444(r27)
	REX_STORE_U32(ctx.r27.u32 + 444, ctx.r14.u32);
	// b 0x8290d494
	goto loc_8290D494;
loc_8290D490:
	// stw r11,444(r27)
	REX_STORE_U32(ctx.r27.u32 + 444, ctx.r11.u32);
loc_8290D494:
	// lwz r10,14728(r27)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r27.u32 + 14728);
	// lwz r8,3360(r27)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r27.u32 + 3360);
	// mullw r10,r10,r8
	ctx.r10.s64 = int64_t(ctx.r10.s32) * int64_t(ctx.r8.s32);
	// rlwinm r10,r10,0,0,24
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 0) & 0xFFFFFF80;
	// cmpwi cr6,r10,0
	ctx.cr6.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// beq cr6,0x8290d4bc
	if (ctx.cr6.eq) goto loc_8290D4BC;
	// li r10,3
	ctx.r10.s64 = 3;
	// stw r10,14732(r27)
	REX_STORE_U32(ctx.r27.u32 + 14732, ctx.r10.u32);
	// li r10,4
	ctx.r10.s64 = 4;
	// b 0x8290d4c8
	goto loc_8290D4C8;
loc_8290D4BC:
	// li r10,4
	ctx.r10.s64 = 4;
	// stw r10,14732(r27)
	REX_STORE_U32(ctx.r27.u32 + 14732, ctx.r10.u32);
	// li r10,3
	ctx.r10.s64 = 3;
loc_8290D4C8:
	// stw r10,14736(r27)
	REX_STORE_U32(ctx.r27.u32 + 14736, ctx.r10.u32);
	// cmpwi cr6,r9,2
	ctx.cr6.compare<int32_t>(ctx.r9.s32, 2, ctx.xer);
	// beq cr6,0x8290d4e0
	if (ctx.cr6.eq) goto loc_8290D4E0;
	// cmpwi cr6,r9,3
	ctx.cr6.compare<int32_t>(ctx.r9.s32, 3, ctx.xer);
	// beq cr6,0x8290d4e0
	if (ctx.cr6.eq) goto loc_8290D4E0;
	// mr r11,r14
	ctx.r11.u64 = ctx.r14.u64;
loc_8290D4E0:
	// lwz r10,1956(r27)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r27.u32 + 1956);
	// li r5,1
	ctx.r5.s64 = 1;
	// stw r11,76(r10)
	REX_STORE_U32(ctx.r10.u32 + 76, ctx.r11.u32);
	// lwz r4,244(r27)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r27.u32 + 244);
	// lwz r3,1956(r27)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r27.u32 + 1956);
	// bl 0x82541180
	ctx.lr = 0x8290D4F8;
	sub_82541180(ctx, base);
	// lwz r11,244(r27)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r27.u32 + 244);
	// cmpwi cr6,r11,5
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 5, ctx.xer);
	// bge cr6,0x8290d514
	if (!ctx.cr6.lt) goto loc_8290D514;
	// addi r11,r27,2448
	ctx.r11.s64 = ctx.r27.s64 + 2448;
	// addi r10,r27,2464
	ctx.r10.s64 = ctx.r27.s64 + 2464;
	// addi r9,r27,2504
	ctx.r9.s64 = ctx.r27.s64 + 2504;
	// b 0x8290d538
	goto loc_8290D538;
loc_8290D514:
	// cmpwi cr6,r11,13
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 13, ctx.xer);
	// bge cr6,0x8290d52c
	if (!ctx.cr6.lt) goto loc_8290D52C;
	// addi r11,r27,2436
	ctx.r11.s64 = ctx.r27.s64 + 2436;
	// addi r10,r27,2476
	ctx.r10.s64 = ctx.r27.s64 + 2476;
	// addi r9,r27,2516
	ctx.r9.s64 = ctx.r27.s64 + 2516;
	// b 0x8290d538
	goto loc_8290D538;
loc_8290D52C:
	// addi r11,r27,2424
	ctx.r11.s64 = ctx.r27.s64 + 2424;
	// addi r10,r27,2488
	ctx.r10.s64 = ctx.r27.s64 + 2488;
	// addi r9,r27,2528
	ctx.r9.s64 = ctx.r27.s64 + 2528;
loc_8290D538:
	// stw r10,2500(r27)
	REX_STORE_U32(ctx.r27.u32 + 2500, ctx.r10.u32);
	// stw r11,2460(r27)
	REX_STORE_U32(ctx.r27.u32 + 2460, ctx.r11.u32);
	// stw r9,2540(r27)
	REX_STORE_U32(ctx.r27.u32 + 2540, ctx.r9.u32);
	// lhz r11,44(r18)
	ctx.r11.u64 = REX_LOAD_U16(ctx.r18.u32 + 44);
	// lwz r10,3348(r27)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r27.u32 + 3348);
	// rlwinm r31,r11,31,1,31
	ctx.r31.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 31) & 0x7FFFFFFF;
	// lhz r11,42(r18)
	ctx.r11.u64 = REX_LOAD_U16(ctx.r18.u32 + 42);
	// cmpwi cr6,r10,1
	ctx.cr6.compare<int32_t>(ctx.r10.s32, 1, ctx.xer);
	// rlwinm r25,r11,31,1,31
	ctx.r25.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 31) & 0x7FFFFFFF;
	// stw r31,140(r1)
	REX_STORE_U32(ctx.r1.u32 + 140, ctx.r31.u32);
	// stw r25,120(r1)
	REX_STORE_U32(ctx.r1.u32 + 120, ctx.r25.u32);
	// bne cr6,0x8290d57c
	if (!ctx.cr6.eq) goto loc_8290D57C;
	// mullw r11,r31,r25
	ctx.r11.s64 = int64_t(ctx.r31.s32) * int64_t(ctx.r25.s32);
	// lwz r3,3020(r27)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r27.u32 + 3020);
	// rlwinm r5,r11,2,0,29
	ctx.r5.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 2) & 0xFFFFFFFC;
	// li r4,0
	ctx.r4.s64 = 0;
	// bl 0x8279f290
	ctx.lr = 0x8290D57C;
	sub_8279F290(ctx, base);
loc_8290D57C:
	// lwz r17,264(r27)
	ctx.r17.u64 = REX_LOAD_U32(ctx.r27.u32 + 264);
	// mr r3,r27
	ctx.r3.u64 = ctx.r27.u64;
	// stw r17,108(r1)
	REX_STORE_U32(ctx.r1.u32 + 108, ctx.r17.u32);
	// bl 0x82501dc8
	ctx.lr = 0x8290D58C;
	sub_82501DC8(ctx, base);
	// mr r4,r18
	ctx.r4.u64 = ctx.r18.u64;
	// mr r3,r27
	ctx.r3.u64 = ctx.r27.u64;
	// bl 0x8252e0e0
	ctx.lr = 0x8290D598;
	sub_8252E0E0(ctx, base);
	// mr r29,r14
	ctx.r29.u64 = ctx.r14.u64;
	// mr r28,r14
	ctx.r28.u64 = ctx.r14.u64;
	// stw r14,80(r1)
	REX_STORE_U32(ctx.r1.u32 + 80, ctx.r14.u32);
	// mr r26,r14
	ctx.r26.u64 = ctx.r14.u64;
	// cmpwi cr6,r31,0
	ctx.cr6.compare<int32_t>(ctx.r31.s32, 0, ctx.xer);
	// stw r29,112(r1)
	REX_STORE_U32(ctx.r1.u32 + 112, ctx.r29.u32);
	// stw r28,116(r1)
	REX_STORE_U32(ctx.r1.u32 + 116, ctx.r28.u32);
	// stw r26,84(r1)
	REX_STORE_U32(ctx.r1.u32 + 84, ctx.r26.u32);
	// ble cr6,0x8290f58c
	if (!ctx.cr6.gt) goto loc_8290F58C;
	// lis r11,-32110
	ctx.r11.s64 = -2104360960;
	// addi r11,r11,-816
	ctx.r11.s64 = ctx.r11.s64 + -816;
	// stw r11,124(r1)
	REX_STORE_U32(ctx.r1.u32 + 124, ctx.r11.u32);
	// lis r11,0
	ctx.r11.s64 = 0;
	// ori r15,r11,32768
	ctx.r15.u64 = ctx.r11.u64 | 32768;
loc_8290D5D0:
	// stw r29,260(r18)
	REX_STORE_U32(ctx.r18.u32 + 260, ctx.r29.u32);
	// stw r28,264(r18)
	REX_STORE_U32(ctx.r18.u32 + 264, ctx.r28.u32);
	// sth r14,270(r18)
	REX_STORE_U16(ctx.r18.u32 + 270, ctx.r14.u16);
	// lwz r11,19104(r27)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r27.u32 + 19104);
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq cr6,0x8290d6b4
	if (ctx.cr6.eq) goto loc_8290D6B4;
	// lwz r11,1124(r18)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r18.u32 + 1124);
	// rlwinm r10,r26,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r26.u32 | (ctx.r26.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r11,r11,r10
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + ctx.r10.u32);
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq cr6,0x8290d6b4
	if (ctx.cr6.eq) goto loc_8290D6B4;
	// lwz r31,0(r18)
	ctx.r31.u64 = REX_LOAD_U32(ctx.r18.u32 + 0);
	// lwz r11,28(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 28);
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq cr6,0x8290d688
	if (ctx.cr6.eq) goto loc_8290D688;
	// lwz r10,8(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 8);
	// li r30,1
	ctx.r30.s64 = 1;
	// addi r11,r10,16
	ctx.r11.s64 = ctx.r10.s64 + 16;
	// cmplwi cr6,r11,1
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 1, ctx.xer);
	// bge cr6,0x8290d660
	if (!ctx.cr6.lt) goto loc_8290D660;
loc_8290D620:
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x8290d660
	if (ctx.cr6.eq) goto loc_8290D660;
	// ld r9,0(r31)
	ctx.r9.u64 = REX_LOAD_U64(ctx.r31.u32 + 0);
	// clrldi r8,r11,32
	ctx.r8.u64 = ctx.r11.u64 & 0xFFFFFFFF;
	// subf. r10,r11,r10
	ctx.r10.u64 = ctx.r10.u64 - ctx.r11.u64;
	ctx.cr0.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// subf r30,r11,r30
	ctx.r30.u64 = ctx.r30.u64 - ctx.r11.u64;
	// stw r10,8(r31)
	REX_STORE_U32(ctx.r31.u32 + 8, ctx.r10.u32);
	// sld r11,r9,r8
	ctx.r11.u64 = ctx.r8.u8 & 0x40 ? 0 : (ctx.r9.u64 << (ctx.r8.u8 & 0x7F));
	// std r11,0(r31)
	REX_STORE_U64(ctx.r31.u32 + 0, ctx.r11.u64);
	// bge 0x8290d650
	if (!ctx.cr0.lt) goto loc_8290D650;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x824c44e8
	ctx.lr = 0x8290D650;
	sub_824C44E8(ctx, base);
loc_8290D650:
	// lwz r10,8(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 8);
	// addi r11,r10,16
	ctx.r11.s64 = ctx.r10.s64 + 16;
	// cmplw cr6,r30,r11
	ctx.cr6.compare<uint32_t>(ctx.r30.u32, ctx.r11.u32, ctx.xer);
	// bgt cr6,0x8290d620
	if (ctx.cr6.gt) goto loc_8290D620;
loc_8290D660:
	// ld r9,0(r31)
	ctx.r9.u64 = REX_LOAD_U64(ctx.r31.u32 + 0);
	// clrldi r10,r30,32
	ctx.r10.u64 = ctx.r30.u64 & 0xFFFFFFFF;
	// lwz r11,8(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 8);
	// subf. r11,r30,r11
	ctx.r11.u64 = ctx.r11.u64 - ctx.r30.u64;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// stw r11,8(r31)
	REX_STORE_U32(ctx.r31.u32 + 8, ctx.r11.u32);
	// sld r10,r9,r10
	ctx.r10.u64 = ctx.r10.u8 & 0x40 ? 0 : (ctx.r9.u64 << (ctx.r10.u8 & 0x7F));
	// std r10,0(r31)
	REX_STORE_U64(ctx.r31.u32 + 0, ctx.r10.u64);
	// bge 0x8290d688
	if (!ctx.cr0.lt) goto loc_8290D688;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x824c44e8
	ctx.lr = 0x8290D688;
	sub_824C44E8(ctx, base);
loc_8290D688:
	// lwz r11,8(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 8);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// clrlwi r4,r11,29
	ctx.r4.u64 = ctx.r11.u32 & 0x7;
	// bl 0x824c45b8
	ctx.lr = 0x8290D698;
	sub_824C45B8(ctx, base);
	// mr r4,r26
	ctx.r4.u64 = ctx.r26.u64;
	// mr r3,r27
	ctx.r3.u64 = ctx.r27.u64;
	// bl 0x824ed718
	ctx.lr = 0x8290D6A4;
	sub_824ED718(ctx, base);
	// li r11,1
	ctx.r11.s64 = 1;
	// cmpwi cr6,r3,0
	ctx.cr6.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// stb r11,1071(r18)
	REX_STORE_U8(ctx.r18.u32 + 1071, ctx.r11.u8);
	// bne cr6,0x8290f5b0
	if (!ctx.cr6.eq) goto loc_8290F5B0;
loc_8290D6B4:
	// stw r14,104(r1)
	REX_STORE_U32(ctx.r1.u32 + 104, ctx.r14.u32);
	// cmpwi cr6,r25,0
	ctx.cr6.compare<int32_t>(ctx.r25.s32, 0, ctx.xer);
	// ble cr6,0x8290f50c
	if (!ctx.cr6.gt) goto loc_8290F50C;
loc_8290D6C0:
	// lwz r11,0(r18)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r18.u32 + 0);
	// li r10,128
	ctx.r10.s64 = 128;
	// lwz r11,12(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 12);
	// dcbt r10,r11
	// lis r12,-4289
	ctx.r12.s64 = -281083904;
	// lwz r11,0(r17)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r17.u32 + 0);
	// mr r19,r14
	ctx.r19.u64 = ctx.r14.u64;
	// ori r12,r12,63743
	ctx.r12.u64 = ctx.r12.u64 | 63743;
	// mr r22,r14
	ctx.r22.u64 = ctx.r14.u64;
	// and r11,r11,r12
	ctx.r11.u64 = ctx.r11.u64 & ctx.r12.u64;
	// mr r30,r14
	ctx.r30.u64 = ctx.r14.u64;
	// mr r21,r14
	ctx.r21.u64 = ctx.r14.u64;
	// mr r20,r14
	ctx.r20.u64 = ctx.r14.u64;
	// stw r11,0(r17)
	REX_STORE_U32(ctx.r17.u32 + 0, ctx.r11.u32);
	// lbz r11,16(r18)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r18.u32 + 16);
	// stb r11,4(r17)
	REX_STORE_U8(ctx.r17.u32 + 4, ctx.r11.u8);
	// lwz r11,1676(r18)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r18.u32 + 1676);
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// bne cr6,0x8290d744
	if (!ctx.cr6.eq) goto loc_8290D744;
	// lwz r3,0(r18)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r18.u32 + 0);
	// ld r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U64(ctx.r3.u32 + 0);
	// lwz r10,8(r3)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r3.u32 + 8);
	// rldicr r9,r11,1,62
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r11.u64, 1) & 0xFFFFFFFFFFFFFFFE;
	// rldicl r8,r11,1,63
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r11.u64, 1) & 0x1;
	// addic. r11,r10,-1
	ctx.xer.ca = ctx.r10.u32 > 0;
	ctx.r11.s64 = ctx.r10.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// rotlwi r31,r8,0
	ctx.r31.u64 = __builtin_rotateleft32(ctx.r8.u32, 0);
	// std r9,0(r3)
	REX_STORE_U64(ctx.r3.u32 + 0, ctx.r9.u64);
	// stw r11,8(r3)
	REX_STORE_U32(ctx.r3.u32 + 8, ctx.r11.u32);
	// bge 0x8290d738
	if (!ctx.cr0.lt) goto loc_8290D738;
	// bl 0x824c44e8
	ctx.lr = 0x8290D738;
	sub_824C44E8(ctx, base);
loc_8290D738:
	// lwz r11,0(r17)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r17.u32 + 0);
	// rlwimi r11,r31,5,24,26
	ctx.r11.u64 = (__builtin_rotateleft64(ctx.r31.u32 | (ctx.r31.u64 << 32), 5) & 0xE0) | (ctx.r11.u64 & 0xFFFFFFFFFFFFFF1F);
	// stw r11,0(r17)
	REX_STORE_U32(ctx.r17.u32 + 0, ctx.r11.u32);
loc_8290D744:
	// lbz r11,18(r18)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r18.u32 + 18);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne cr6,0x8290d788
	if (!ctx.cr6.eq) goto loc_8290D788;
	// lwz r3,0(r18)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r18.u32 + 0);
	// ld r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U64(ctx.r3.u32 + 0);
	// lwz r10,8(r3)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r3.u32 + 8);
	// rldicr r9,r11,1,62
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r11.u64, 1) & 0xFFFFFFFFFFFFFFFE;
	// rldicl r8,r11,1,63
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r11.u64, 1) & 0x1;
	// addic. r11,r10,-1
	ctx.xer.ca = ctx.r10.u32 > 0;
	ctx.r11.s64 = ctx.r10.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// rotlwi r31,r8,0
	ctx.r31.u64 = __builtin_rotateleft32(ctx.r8.u32, 0);
	// std r9,0(r3)
	REX_STORE_U64(ctx.r3.u32 + 0, ctx.r9.u64);
	// stw r11,8(r3)
	REX_STORE_U32(ctx.r3.u32 + 8, ctx.r11.u32);
	// bge 0x8290d77c
	if (!ctx.cr0.lt) goto loc_8290D77C;
	// bl 0x824c44e8
	ctx.lr = 0x8290D77C;
	sub_824C44E8(ctx, base);
loc_8290D77C:
	// lwz r11,0(r17)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r17.u32 + 0);
	// rlwimi r11,r31,31,0,0
	ctx.r11.u64 = (__builtin_rotateleft64(ctx.r31.u32 | (ctx.r31.u64 << 32), 31) & 0x80000000) | (ctx.r11.u64 & 0xFFFFFFFF7FFFFFFF);
	// stw r11,0(r17)
	REX_STORE_U32(ctx.r17.u32 + 0, ctx.r11.u32);
loc_8290D788:
	// lwz r11,0(r17)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r17.u32 + 0);
	// rlwinm r10,r11,0,24,26
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 0) & 0xE0;
	// cmplwi cr6,r10,32
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 32, ctx.xer);
	// bne cr6,0x8290d7a0
	if (!ctx.cr6.eq) goto loc_8290D7A0;
	// li r30,1
	ctx.r30.s64 = 1;
	// b 0x8290dc64
	goto loc_8290DC64;
loc_8290D7A0:
	// rlwinm r11,r11,0,0,0
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 0) & 0x80000000;
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne cr6,0x8290dba0
	if (!ctx.cr6.eq) goto loc_8290DBA0;
	// lwz r31,0(r18)
	ctx.r31.u64 = REX_LOAD_U32(ctx.r18.u32 + 0);
	// lwz r11,100(r18)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r18.u32 + 100);
	// ld r9,0(r31)
	ctx.r9.u64 = REX_LOAD_U64(ctx.r31.u32 + 0);
	// lwz r28,0(r11)
	ctx.r28.u64 = REX_LOAD_U32(ctx.r11.u32 + 0);
	// rldicl r11,r9,10,54
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r9.u64, 10) & 0x3FF;
	// rlwinm r11,r11,1,0,30
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 1) & 0xFFFFFFFE;
	// lhzx r11,r11,r28
	ctx.r11.u64 = REX_LOAD_U16(ctx.r11.u32 + ctx.r28.u32);
	// extsh r30,r11
	ctx.r30.s64 = ctx.r11.s16;
	// cmpwi cr6,r30,0
	ctx.cr6.compare<int32_t>(ctx.r30.s32, 0, ctx.xer);
	// blt cr6,0x8290d894
	if (ctx.cr6.lt) goto loc_8290D894;
	// clrlwi r11,r30,28
	ctx.r11.u64 = ctx.r30.u32 & 0xF;
	// lwz r10,8(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 8);
	// cmpw cr6,r10,r11
	ctx.cr6.compare<int32_t>(ctx.r10.s32, ctx.r11.s32, ctx.xer);
	// sld r9,r9,r11
	ctx.r9.u64 = ctx.r11.u8 & 0x40 ? 0 : (ctx.r9.u64 << (ctx.r11.u8 & 0x7F));
	// std r9,0(r31)
	REX_STORE_U64(ctx.r31.u32 + 0, ctx.r9.u64);
	// subf r9,r11,r10
	ctx.r9.u64 = ctx.r10.u64 - ctx.r11.u64;
	// stw r9,8(r31)
	REX_STORE_U32(ctx.r31.u32 + 8, ctx.r9.u32);
	// bge cr6,0x8290d88c
	if (!ctx.cr6.lt) goto loc_8290D88C;
loc_8290D7F4:
	// lwz r10,16(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 16);
	// lwz r11,12(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 12);
	// addi r10,r10,-4
	ctx.r10.s64 = ctx.r10.s64 + -4;
	// cmplw cr6,r11,r10
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, ctx.r10.u32, ctx.xer);
	// blt cr6,0x8290d820
	if (ctx.cr6.lt) goto loc_8290D820;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x824c4428
	ctx.lr = 0x8290D810;
	sub_824C4428(ctx, base);
	// cmplwi cr6,r3,1
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 1, ctx.xer);
	// beq cr6,0x8290d7f4
	if (ctx.cr6.eq) goto loc_8290D7F4;
	// srawi r30,r30,4
	ctx.xer.ca = (ctx.r30.s32 < 0) & ((ctx.r30.u32 & 0xF) != 0);
	ctx.r30.s64 = ctx.r30.s32 >> 4;
	// b 0x8290d8d4
	goto loc_8290D8D4;
loc_8290D820:
	// lbz r8,0(r11)
	ctx.r8.u64 = REX_LOAD_U8(ctx.r11.u32 + 0);
	// addi r4,r11,6
	ctx.r4.s64 = ctx.r11.s64 + 6;
	// lbz r9,1(r11)
	ctx.r9.u64 = REX_LOAD_U8(ctx.r11.u32 + 1);
	// rldicr r8,r8,8,63
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r8.u64, 8) & 0xFFFFFFFFFFFFFFFF;
	// lbz r5,2(r11)
	ctx.r5.u64 = REX_LOAD_U8(ctx.r11.u32 + 2);
	// lbz r6,3(r11)
	ctx.r6.u64 = REX_LOAD_U8(ctx.r11.u32 + 3);
	// add r9,r9,r8
	ctx.r9.u64 = ctx.r9.u64 + ctx.r8.u64;
	// lbz r8,5(r11)
	ctx.r8.u64 = REX_LOAD_U8(ctx.r11.u32 + 5);
	// lbz r7,4(r11)
	ctx.r7.u64 = REX_LOAD_U8(ctx.r11.u32 + 4);
	// rldicr r11,r9,8,55
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r9.u64, 8) & 0xFFFFFFFFFFFFFF00;
	// lwz r10,8(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 8);
	// ld r9,0(r31)
	ctx.r9.u64 = REX_LOAD_U64(ctx.r31.u32 + 0);
	// add r11,r11,r5
	ctx.r11.u64 = ctx.r11.u64 + ctx.r5.u64;
	// stw r4,12(r31)
	REX_STORE_U32(ctx.r31.u32 + 12, ctx.r4.u32);
	// rldicr r11,r11,8,55
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u64, 8) & 0xFFFFFFFFFFFFFF00;
	// add r11,r11,r6
	ctx.r11.u64 = ctx.r11.u64 + ctx.r6.u64;
	// rldicr r11,r11,8,55
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u64, 8) & 0xFFFFFFFFFFFFFF00;
	// add r11,r11,r7
	ctx.r11.u64 = ctx.r11.u64 + ctx.r7.u64;
	// rldicr r11,r11,8,55
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u64, 8) & 0xFFFFFFFFFFFFFF00;
	// add r11,r11,r8
	ctx.r11.u64 = ctx.r11.u64 + ctx.r8.u64;
	// neg r8,r10
	ctx.r8.s64 = static_cast<int64_t>(-ctx.r10.u64);
	// addi r10,r10,48
	ctx.r10.s64 = ctx.r10.s64 + 48;
	// extsw r8,r8
	ctx.r8.s64 = ctx.r8.s32;
	// stw r10,8(r31)
	REX_STORE_U32(ctx.r31.u32 + 8, ctx.r10.u32);
	// sld r11,r11,r8
	ctx.r11.u64 = ctx.r8.u8 & 0x40 ? 0 : (ctx.r11.u64 << (ctx.r8.u8 & 0x7F));
	// add r11,r11,r9
	ctx.r11.u64 = ctx.r11.u64 + ctx.r9.u64;
	// std r11,0(r31)
	REX_STORE_U64(ctx.r31.u32 + 0, ctx.r11.u64);
loc_8290D88C:
	// srawi r30,r30,4
	ctx.xer.ca = (ctx.r30.s32 < 0) & ((ctx.r30.u32 & 0xF) != 0);
	ctx.r30.s64 = ctx.r30.s32 >> 4;
	// b 0x8290d8d4
	goto loc_8290D8D4;
loc_8290D894:
	// li r4,10
	ctx.r4.s64 = 10;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x824c45b8
	ctx.lr = 0x8290D8A0;
	sub_824C45B8(ctx, base);
loc_8290D8A0:
	// ld r11,0(r31)
	ctx.r11.u64 = REX_LOAD_U64(ctx.r31.u32 + 0);
	// li r4,1
	ctx.r4.s64 = 1;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// rldicl r11,r11,1,63
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u64, 1) & 0x1;
	// rotlwi r29,r11,0
	ctx.r29.u64 = __builtin_rotateleft32(ctx.r11.u32, 0);
	// bl 0x824c45b8
	ctx.lr = 0x8290D8B8;
	sub_824C45B8(ctx, base);
	// add r11,r29,r30
	ctx.r11.u64 = ctx.r29.u64 + ctx.r30.u64;
	// add r11,r11,r15
	ctx.r11.u64 = ctx.r11.u64 + ctx.r15.u64;
	// rlwinm r11,r11,1,0,30
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 1) & 0xFFFFFFFE;
	// lhzx r11,r11,r28
	ctx.r11.u64 = REX_LOAD_U16(ctx.r11.u32 + ctx.r28.u32);
	// extsh r30,r11
	ctx.r30.s64 = ctx.r11.s16;
	// cmpwi cr6,r30,0
	ctx.cr6.compare<int32_t>(ctx.r30.s32, 0, ctx.xer);
	// blt cr6,0x8290d8a0
	if (ctx.cr6.lt) goto loc_8290D8A0;
loc_8290D8D4:
	// addi r11,r30,1
	ctx.r11.s64 = ctx.r30.s64 + 1;
	// li r10,1
	ctx.r10.s64 = 1;
	// cmpwi cr6,r11,37
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 37, ctx.xer);
	// bge cr6,0x8290d8e8
	if (!ctx.cr6.lt) goto loc_8290D8E8;
	// mr r10,r14
	ctx.r10.u64 = ctx.r14.u64;
loc_8290D8E8:
	// extsw r23,r10
	ctx.r23.s64 = ctx.r10.s32;
	// cmpwi cr6,r10,0
	ctx.cr6.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// beq cr6,0x8290d8f8
	if (ctx.cr6.eq) goto loc_8290D8F8;
	// addi r11,r11,-37
	ctx.r11.s64 = ctx.r11.s64 + -37;
loc_8290D8F8:
	// mr r24,r14
	ctx.r24.u64 = ctx.r14.u64;
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// bne cr6,0x8290d90c
	if (!ctx.cr6.eq) goto loc_8290D90C;
	// mr r11,r14
	ctx.r11.u64 = ctx.r14.u64;
	// b 0x8290db78
	goto loc_8290DB78;
loc_8290D90C:
	// cmpwi cr6,r11,35
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 35, ctx.xer);
	// bge cr6,0x8290da60
	if (!ctx.cr6.lt) goto loc_8290DA60;
	// lwz r10,12(r18)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r18.u32 + 12);
	// rlwinm r11,r11,2,0,29
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r11,r11,r10
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + ctx.r10.u32);
	// srawi r9,r11,24
	ctx.xer.ca = (ctx.r11.s32 < 0) & ((ctx.r11.u32 & 0xFFFFFF) != 0);
	ctx.r9.s64 = ctx.r11.s32 >> 24;
	// srawi r8,r11,4
	ctx.xer.ca = (ctx.r11.s32 < 0) & ((ctx.r11.u32 & 0xF) != 0);
	ctx.r8.s64 = ctx.r11.s32 >> 4;
	// clrlwi r10,r11,28
	ctx.r10.u64 = ctx.r11.u32 & 0xF;
	// clrlwi r28,r8,28
	ctx.r28.u64 = ctx.r8.u32 & 0xF;
	// srawi r8,r11,8
	ctx.xer.ca = (ctx.r11.s32 < 0) & ((ctx.r11.u32 & 0xFF) != 0);
	ctx.r8.s64 = ctx.r11.s32 >> 8;
	// srawi r11,r11,16
	ctx.xer.ca = (ctx.r11.s32 < 0) & ((ctx.r11.u32 & 0xFFFF) != 0);
	ctx.r11.s64 = ctx.r11.s32 >> 16;
	// add r30,r10,r28
	ctx.r30.u64 = ctx.r10.u64 + ctx.r28.u64;
	// clrlwi r27,r9,24
	ctx.r27.u64 = ctx.r9.u32 & 0xFF;
	// clrlwi r26,r8,24
	ctx.r26.u64 = ctx.r8.u32 & 0xFF;
	// clrlwi r25,r11,24
	ctx.r25.u64 = ctx.r11.u32 & 0xFF;
	// cmpwi cr6,r30,0
	ctx.cr6.compare<int32_t>(ctx.r30.s32, 0, ctx.xer);
	// ble cr6,0x8290da08
	if (!ctx.cr6.gt) goto loc_8290DA08;
	// lwz r9,8(r31)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r31.u32 + 8);
	// mr r29,r14
	ctx.r29.u64 = ctx.r14.u64;
	// cmplwi cr6,r30,0
	ctx.cr6.compare<uint32_t>(ctx.r30.u32, 0, ctx.xer);
	// addi r11,r9,16
	ctx.r11.s64 = ctx.r9.s64 + 16;
	// beq cr6,0x8290da08
	if (ctx.cr6.eq) goto loc_8290DA08;
	// cmplw cr6,r30,r11
	ctx.cr6.compare<uint32_t>(ctx.r30.u32, ctx.r11.u32, ctx.xer);
	// ble cr6,0x8290d9c4
	if (!ctx.cr6.gt) goto loc_8290D9C4;
loc_8290D96C:
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x8290d9c4
	if (ctx.cr6.eq) goto loc_8290D9C4;
	// subfic r8,r11,64
	ctx.xer.ca = ctx.r11.u32 <= 64;
	ctx.r8.u64 = static_cast<uint64_t>(64) - ctx.r11.u64;
	// ld r10,0(r31)
	ctx.r10.u64 = REX_LOAD_U64(ctx.r31.u32 + 0);
	// subf. r9,r11,r9
	ctx.r9.u64 = ctx.r9.u64 - ctx.r11.u64;
	ctx.cr0.compare<int32_t>(ctx.r9.s32, 0, ctx.xer);
	// clrldi r8,r8,32
	ctx.r8.u64 = ctx.r8.u64 & 0xFFFFFFFF;
	// subf r30,r11,r30
	ctx.r30.u64 = ctx.r30.u64 - ctx.r11.u64;
	// clrldi r11,r11,32
	ctx.r11.u64 = ctx.r11.u64 & 0xFFFFFFFF;
	// stw r9,8(r31)
	REX_STORE_U32(ctx.r31.u32 + 8, ctx.r9.u32);
	// srd r8,r10,r8
	ctx.r8.u64 = ctx.r8.u8 & 0x40 ? 0 : (ctx.r10.u64 >> (ctx.r8.u8 & 0x7F));
	// sld r11,r10,r11
	ctx.r11.u64 = ctx.r11.u8 & 0x40 ? 0 : (ctx.r10.u64 << (ctx.r11.u8 & 0x7F));
	// rotlwi r10,r8,0
	ctx.r10.u64 = __builtin_rotateleft32(ctx.r8.u32, 0);
	// std r11,0(r31)
	REX_STORE_U64(ctx.r31.u32 + 0, ctx.r11.u64);
	// slw r11,r10,r30
	ctx.r11.u64 = ctx.r30.u8 & 0x20 ? 0 : (ctx.r10.u32 << (ctx.r30.u8 & 0x3F));
	// add r29,r11,r29
	ctx.r29.u64 = ctx.r11.u64 + ctx.r29.u64;
	// bge 0x8290d9b4
	if (!ctx.cr0.lt) goto loc_8290D9B4;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x824c44e8
	ctx.lr = 0x8290D9B4;
	sub_824C44E8(ctx, base);
loc_8290D9B4:
	// lwz r9,8(r31)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r31.u32 + 8);
	// addi r11,r9,16
	ctx.r11.s64 = ctx.r9.s64 + 16;
	// cmplw cr6,r30,r11
	ctx.cr6.compare<uint32_t>(ctx.r30.u32, ctx.r11.u32, ctx.xer);
	// bgt cr6,0x8290d96c
	if (ctx.cr6.gt) goto loc_8290D96C;
loc_8290D9C4:
	// subfic r9,r30,64
	ctx.xer.ca = ctx.r30.u32 <= 64;
	ctx.r9.u64 = static_cast<uint64_t>(64) - ctx.r30.u64;
	// ld r11,0(r31)
	ctx.r11.u64 = REX_LOAD_U64(ctx.r31.u32 + 0);
	// clrldi r8,r30,32
	ctx.r8.u64 = ctx.r30.u64 & 0xFFFFFFFF;
	// lwz r10,8(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 8);
	// clrldi r9,r9,32
	ctx.r9.u64 = ctx.r9.u64 & 0xFFFFFFFF;
	// subf. r10,r30,r10
	ctx.r10.u64 = ctx.r10.u64 - ctx.r30.u64;
	ctx.cr0.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// stw r10,8(r31)
	REX_STORE_U32(ctx.r31.u32 + 8, ctx.r10.u32);
	// sld r8,r11,r8
	ctx.r8.u64 = ctx.r8.u8 & 0x40 ? 0 : (ctx.r11.u64 << (ctx.r8.u8 & 0x7F));
	// srd r9,r11,r9
	ctx.r9.u64 = ctx.r9.u8 & 0x40 ? 0 : (ctx.r11.u64 >> (ctx.r9.u8 & 0x7F));
	// rotlwi r11,r9,0
	ctx.r11.u64 = __builtin_rotateleft32(ctx.r9.u32, 0);
	// add r30,r11,r29
	ctx.r30.u64 = ctx.r11.u64 + ctx.r29.u64;
	// std r8,0(r31)
	REX_STORE_U64(ctx.r31.u32 + 0, ctx.r8.u64);
	// bge 0x8290da00
	if (!ctx.cr0.lt) goto loc_8290DA00;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x824c44e8
	ctx.lr = 0x8290DA00;
	sub_824C44E8(ctx, base);
loc_8290DA00:
	// mr r10,r30
	ctx.r10.u64 = ctx.r30.u64;
	// b 0x8290da0c
	goto loc_8290DA0C;
loc_8290DA08:
	// mr r10,r14
	ctx.r10.u64 = ctx.r14.u64;
loc_8290DA0C:
	// and r11,r10,r27
	ctx.r11.u64 = ctx.r10.u64 & ctx.r27.u64;
	// rlwinm r8,r25,1,0,30
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r25.u32 | (ctx.r25.u64 << 32), 1) & 0xFFFFFFFE;
	// rlwinm r9,r11,0,0,30
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 0) & 0xFFFFFFFE;
	// sraw r10,r10,r28
	temp.u32 = ctx.r28.u32 & 0x3F;
	if (temp.u32 > 0x1F) temp.u32 = 0x1F;
	ctx.xer.ca = (ctx.r10.s32 < 0) & (((ctx.r10.s32 >> temp.u32) << temp.u32) != ctx.r10.s32);
	ctx.r10.s64 = ctx.r10.s32 >> temp.u32;
	// add r9,r9,r8
	ctx.r9.u64 = ctx.r9.u64 + ctx.r8.u64;
	// clrlwi r7,r11,31
	ctx.r7.u64 = ctx.r11.u32 & 0x1;
	// rlwinm r8,r9,15,0,16
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 15) & 0xFFFF8000;
	// clrlwi r9,r10,31
	ctx.r9.u64 = ctx.r10.u32 & 0x1;
	// srawi r10,r10,1
	ctx.xer.ca = (ctx.r10.s32 < 0) & ((ctx.r10.u32 & 0x1) != 0);
	ctx.r10.s64 = ctx.r10.s32 >> 1;
	// neg r11,r7
	ctx.r11.s64 = static_cast<int64_t>(-ctx.r7.u64);
	// add r10,r10,r26
	ctx.r10.u64 = ctx.r10.u64 + ctx.r26.u64;
	// neg r9,r9
	ctx.r9.s64 = static_cast<int64_t>(-ctx.r9.u64);
	// rlwinm r7,r11,16,0,15
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 16) & 0xFFFF0000;
	// xor r10,r10,r9
	ctx.r10.u64 = ctx.r10.u64 ^ ctx.r9.u64;
	// rlwinm r11,r11,16,0,15
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 16) & 0xFFFF0000;
	// xor r8,r8,r7
	ctx.r8.u64 = ctx.r8.u64 ^ ctx.r7.u64;
	// subf r10,r9,r10
	ctx.r10.u64 = ctx.r10.u64 - ctx.r9.u64;
	// subf r11,r11,r8
	ctx.r11.u64 = ctx.r8.u64 - ctx.r11.u64;
	// clrlwi r10,r10,16
	ctx.r10.u64 = ctx.r10.u32 & 0xFFFF;
	// or r11,r11,r10
	ctx.r11.u64 = ctx.r11.u64 | ctx.r10.u64;
	// b 0x8290db78
	goto loc_8290DB78;
loc_8290DA60:
	// cmpwi cr6,r11,36
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 36, ctx.xer);
	// bne cr6,0x8290da74
	if (!ctx.cr6.eq) goto loc_8290DA74;
	// li r24,1
	ctx.r24.s64 = 1;
	// mr r11,r14
	ctx.r11.u64 = ctx.r14.u64;
	// b 0x8290db78
	goto loc_8290DB78;
loc_8290DA74:
	// lbz r11,22(r18)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r18.u32 + 22);
	// mr r29,r14
	ctx.r29.u64 = ctx.r14.u64;
	// lhz r10,62(r18)
	ctx.r10.u64 = REX_LOAD_U16(ctx.r18.u32 + 62);
	// lhz r9,64(r18)
	ctx.r9.u64 = REX_LOAD_U16(ctx.r18.u32 + 64);
	// subf r27,r11,r10
	ctx.r27.u64 = ctx.r10.u64 - ctx.r11.u64;
	// lwz r10,8(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 8);
	// subf r28,r11,r9
	ctx.r28.u64 = ctx.r9.u64 - ctx.r11.u64;
	// addi r11,r10,16
	ctx.r11.s64 = ctx.r10.s64 + 16;
	// add r30,r28,r27
	ctx.r30.u64 = ctx.r28.u64 + ctx.r27.u64;
	// cmplwi cr6,r30,0
	ctx.cr6.compare<uint32_t>(ctx.r30.u32, 0, ctx.xer);
	// bne cr6,0x8290daa8
	if (!ctx.cr6.eq) goto loc_8290DAA8;
	// mr r11,r14
	ctx.r11.u64 = ctx.r14.u64;
	// b 0x8290db48
	goto loc_8290DB48;
loc_8290DAA8:
	// cmplw cr6,r30,r11
	ctx.cr6.compare<uint32_t>(ctx.r30.u32, ctx.r11.u32, ctx.xer);
	// ble cr6,0x8290db08
	if (!ctx.cr6.gt) goto loc_8290DB08;
loc_8290DAB0:
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x8290db08
	if (ctx.cr6.eq) goto loc_8290DB08;
	// subfic r8,r11,64
	ctx.xer.ca = ctx.r11.u32 <= 64;
	ctx.r8.u64 = static_cast<uint64_t>(64) - ctx.r11.u64;
	// ld r9,0(r31)
	ctx.r9.u64 = REX_LOAD_U64(ctx.r31.u32 + 0);
	// subf. r10,r11,r10
	ctx.r10.u64 = ctx.r10.u64 - ctx.r11.u64;
	ctx.cr0.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// clrldi r8,r8,32
	ctx.r8.u64 = ctx.r8.u64 & 0xFFFFFFFF;
	// subf r30,r11,r30
	ctx.r30.u64 = ctx.r30.u64 - ctx.r11.u64;
	// clrldi r11,r11,32
	ctx.r11.u64 = ctx.r11.u64 & 0xFFFFFFFF;
	// stw r10,8(r31)
	REX_STORE_U32(ctx.r31.u32 + 8, ctx.r10.u32);
	// srd r8,r9,r8
	ctx.r8.u64 = ctx.r8.u8 & 0x40 ? 0 : (ctx.r9.u64 >> (ctx.r8.u8 & 0x7F));
	// sld r11,r9,r11
	ctx.r11.u64 = ctx.r11.u8 & 0x40 ? 0 : (ctx.r9.u64 << (ctx.r11.u8 & 0x7F));
	// rotlwi r9,r8,0
	ctx.r9.u64 = __builtin_rotateleft32(ctx.r8.u32, 0);
	// std r11,0(r31)
	REX_STORE_U64(ctx.r31.u32 + 0, ctx.r11.u64);
	// slw r11,r9,r30
	ctx.r11.u64 = ctx.r30.u8 & 0x20 ? 0 : (ctx.r9.u32 << (ctx.r30.u8 & 0x3F));
	// add r29,r11,r29
	ctx.r29.u64 = ctx.r11.u64 + ctx.r29.u64;
	// bge 0x8290daf8
	if (!ctx.cr0.lt) goto loc_8290DAF8;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x824c44e8
	ctx.lr = 0x8290DAF8;
	sub_824C44E8(ctx, base);
loc_8290DAF8:
	// lwz r10,8(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 8);
	// addi r11,r10,16
	ctx.r11.s64 = ctx.r10.s64 + 16;
	// cmplw cr6,r30,r11
	ctx.cr6.compare<uint32_t>(ctx.r30.u32, ctx.r11.u32, ctx.xer);
	// bgt cr6,0x8290dab0
	if (ctx.cr6.gt) goto loc_8290DAB0;
loc_8290DB08:
	// subfic r9,r30,64
	ctx.xer.ca = ctx.r30.u32 <= 64;
	ctx.r9.u64 = static_cast<uint64_t>(64) - ctx.r30.u64;
	// ld r11,0(r31)
	ctx.r11.u64 = REX_LOAD_U64(ctx.r31.u32 + 0);
	// clrldi r8,r30,32
	ctx.r8.u64 = ctx.r30.u64 & 0xFFFFFFFF;
	// lwz r10,8(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 8);
	// clrldi r9,r9,32
	ctx.r9.u64 = ctx.r9.u64 & 0xFFFFFFFF;
	// subf. r10,r30,r10
	ctx.r10.u64 = ctx.r10.u64 - ctx.r30.u64;
	ctx.cr0.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// stw r10,8(r31)
	REX_STORE_U32(ctx.r31.u32 + 8, ctx.r10.u32);
	// sld r8,r11,r8
	ctx.r8.u64 = ctx.r8.u8 & 0x40 ? 0 : (ctx.r11.u64 << (ctx.r8.u8 & 0x7F));
	// srd r9,r11,r9
	ctx.r9.u64 = ctx.r9.u8 & 0x40 ? 0 : (ctx.r11.u64 >> (ctx.r9.u8 & 0x7F));
	// rotlwi r11,r9,0
	ctx.r11.u64 = __builtin_rotateleft32(ctx.r9.u32, 0);
	// add r30,r11,r29
	ctx.r30.u64 = ctx.r11.u64 + ctx.r29.u64;
	// std r8,0(r31)
	REX_STORE_U64(ctx.r31.u32 + 0, ctx.r8.u64);
	// bge 0x8290db44
	if (!ctx.cr0.lt) goto loc_8290DB44;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x824c44e8
	ctx.lr = 0x8290DB44;
	sub_824C44E8(ctx, base);
loc_8290DB44:
	// mr r11,r30
	ctx.r11.u64 = ctx.r30.u64;
loc_8290DB48:
	// li r10,1
	ctx.r10.s64 = 1;
	// rlwinm r9,r11,16,0,15
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 16) & 0xFFFF0000;
	// sraw r11,r11,r28
	temp.u32 = ctx.r28.u32 & 0x3F;
	if (temp.u32 > 0x1F) temp.u32 = 0x1F;
	ctx.xer.ca = (ctx.r11.s32 < 0) & (((ctx.r11.s32 >> temp.u32) << temp.u32) != ctx.r11.s32);
	ctx.r11.s64 = ctx.r11.s32 >> temp.u32;
	// slw r8,r10,r28
	ctx.r8.u64 = ctx.r28.u8 & 0x20 ? 0 : (ctx.r10.u32 << (ctx.r28.u8 & 0x3F));
	// slw r10,r10,r27
	ctx.r10.u64 = ctx.r27.u8 & 0x20 ? 0 : (ctx.r10.u32 << (ctx.r27.u8 & 0x3F));
	// rlwinm r8,r8,16,0,15
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 16) & 0xFFFF0000;
	// addi r10,r10,-1
	ctx.r10.s64 = ctx.r10.s64 + -1;
	// addis r8,r8,-1
	ctx.r8.s64 = ctx.r8.s64 + -65536;
	// and r11,r11,r10
	ctx.r11.u64 = ctx.r11.u64 & ctx.r10.u64;
	// and r10,r8,r9
	ctx.r10.u64 = ctx.r8.u64 & ctx.r9.u64;
	// clrlwi r11,r11,16
	ctx.r11.u64 = ctx.r11.u32 & 0xFFFF;
	// or r11,r10,r11
	ctx.r11.u64 = ctx.r10.u64 | ctx.r11.u64;
loc_8290DB78:
	// rldicr r10,r23,8,55
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r23.u64, 8) & 0xFFFFFFFFFFFFFF00;
	// clrldi r11,r11,32
	ctx.r11.u64 = ctx.r11.u64 & 0xFFFFFFFF;
	// or r10,r10,r24
	ctx.r10.u64 = ctx.r10.u64 | ctx.r24.u64;
	// rldicr r10,r10,32,31
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u64, 32) & 0xFFFFFFFF00000000;
	// or r11,r10,r11
	ctx.r11.u64 = ctx.r10.u64 | ctx.r11.u64;
	// rldicl r10,r11,24,40
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r11.u64, 24) & 0xFFFFFF;
	// rldicl r9,r11,32,32
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r11.u64, 32) & 0xFFFFFFFF;
	// clrlwi r30,r10,31
	ctx.r30.u64 = ctx.r10.u32 & 0x1;
	// clrlwi r22,r9,31
	ctx.r22.u64 = ctx.r9.u32 & 0x1;
	// rotlwi r21,r11,0
	ctx.r21.u64 = __builtin_rotateleft32(ctx.r11.u32, 0);
loc_8290DBA0:
	// lwz r11,0(r17)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r17.u32 + 0);
	// rlwinm r10,r11,0,24,26
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 0) & 0xE0;
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// bne cr6,0x8290dc64
	if (!ctx.cr6.eq) goto loc_8290DC64;
	// cmpwi cr6,r22,0
	ctx.cr6.compare<int32_t>(ctx.r22.s32, 0, ctx.xer);
	// beq cr6,0x8290dbc4
	if (ctx.cr6.eq) goto loc_8290DBC4;
	// li r10,3
	ctx.r10.s64 = 3;
	// rlwimi r11,r10,5,24,26
	ctx.r11.u64 = (__builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 5) & 0xE0) | (ctx.r11.u64 & 0xFFFFFFFFFFFFFF1F);
	// b 0x8290dc60
	goto loc_8290DC60;
loc_8290DBC4:
	// lwz r3,0(r18)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r18.u32 + 0);
	// ld r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U64(ctx.r3.u32 + 0);
	// lwz r10,8(r3)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r3.u32 + 8);
	// rldicr r9,r11,1,62
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r11.u64, 1) & 0xFFFFFFFFFFFFFFFE;
	// rldicl r8,r11,1,63
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r11.u64, 1) & 0x1;
	// addic. r11,r10,-1
	ctx.xer.ca = ctx.r10.u32 > 0;
	ctx.r11.s64 = ctx.r10.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// rotlwi r31,r8,0
	ctx.r31.u64 = __builtin_rotateleft32(ctx.r8.u32, 0);
	// std r9,0(r3)
	REX_STORE_U64(ctx.r3.u32 + 0, ctx.r9.u64);
	// stw r11,8(r3)
	REX_STORE_U32(ctx.r3.u32 + 8, ctx.r11.u32);
	// bge 0x8290dbf0
	if (!ctx.cr0.lt) goto loc_8290DBF0;
	// bl 0x824c44e8
	ctx.lr = 0x8290DBF0;
	sub_824C44E8(ctx, base);
loc_8290DBF0:
	// cmplwi cr6,r31,0
	ctx.cr6.compare<uint32_t>(ctx.r31.u32, 0, ctx.xer);
	// bne cr6,0x8290dc0c
	if (!ctx.cr6.eq) goto loc_8290DC0C;
	// lwz r11,1680(r18)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r18.u32 + 1680);
	// lwz r10,0(r17)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r17.u32 + 0);
	// rlwimi r10,r11,5,24,26
	ctx.r10.u64 = (__builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 5) & 0xE0) | (ctx.r10.u64 & 0xFFFFFFFFFFFFFF1F);
	// stw r10,0(r17)
	REX_STORE_U32(ctx.r17.u32 + 0, ctx.r10.u32);
	// b 0x8290dc64
	goto loc_8290DC64;
loc_8290DC0C:
	// lwz r3,0(r18)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r18.u32 + 0);
	// ld r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U64(ctx.r3.u32 + 0);
	// lwz r10,8(r3)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r3.u32 + 8);
	// rldicr r9,r11,1,62
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r11.u64, 1) & 0xFFFFFFFFFFFFFFFE;
	// rldicl r8,r11,1,63
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r11.u64, 1) & 0x1;
	// addic. r11,r10,-1
	ctx.xer.ca = ctx.r10.u32 > 0;
	ctx.r11.s64 = ctx.r10.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// rotlwi r31,r8,0
	ctx.r31.u64 = __builtin_rotateleft32(ctx.r8.u32, 0);
	// std r9,0(r3)
	REX_STORE_U64(ctx.r3.u32 + 0, ctx.r9.u64);
	// stw r11,8(r3)
	REX_STORE_U32(ctx.r3.u32 + 8, ctx.r11.u32);
	// bge 0x8290dc38
	if (!ctx.cr0.lt) goto loc_8290DC38;
	// bl 0x824c44e8
	ctx.lr = 0x8290DC38;
	sub_824C44E8(ctx, base);
loc_8290DC38:
	// cmplwi cr6,r31,0
	ctx.cr6.compare<uint32_t>(ctx.r31.u32, 0, ctx.xer);
	// bne cr6,0x8290dc54
	if (!ctx.cr6.eq) goto loc_8290DC54;
	// lwz r11,1684(r18)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r18.u32 + 1684);
	// lwz r10,0(r17)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r17.u32 + 0);
	// rlwimi r10,r11,5,24,26
	ctx.r10.u64 = (__builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 5) & 0xE0) | (ctx.r10.u64 & 0xFFFFFFFFFFFFFF1F);
	// stw r10,0(r17)
	REX_STORE_U32(ctx.r17.u32 + 0, ctx.r10.u32);
	// b 0x8290dc64
	goto loc_8290DC64;
loc_8290DC54:
	// lwz r11,0(r17)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r17.u32 + 0);
	// li r10,1
	ctx.r10.s64 = 1;
	// rlwimi r11,r10,6,24,26
	ctx.r11.u64 = (__builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 6) & 0xE0) | (ctx.r11.u64 & 0xFFFFFFFFFFFFFF1F);
loc_8290DC60:
	// stw r11,0(r17)
	REX_STORE_U32(ctx.r17.u32 + 0, ctx.r11.u32);
loc_8290DC64:
	// lwz r11,0(r17)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r17.u32 + 0);
	// rlwinm r10,r11,0,0,0
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 0) & 0x80000000;
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// beq cr6,0x8290dc7c
	if (ctx.cr6.eq) goto loc_8290DC7C;
	// stb r14,5(r17)
	REX_STORE_U8(ctx.r17.u32 + 5, ctx.r14.u8);
	// b 0x8290ea6c
	goto loc_8290EA6C;
loc_8290DC7C:
	// cmpwi cr6,r30,0
	ctx.cr6.compare<int32_t>(ctx.r30.s32, 0, ctx.xer);
	// bne cr6,0x8290df9c
	if (!ctx.cr6.eq) goto loc_8290DF9C;
	// oris r11,r11,16384
	ctx.r11.u64 = ctx.r11.u64 | 1073741824;
	// stw r11,0(r17)
	REX_STORE_U32(ctx.r17.u32 + 0, ctx.r11.u32);
	// lbz r10,19(r18)
	ctx.r10.u64 = REX_LOAD_U8(ctx.r18.u32 + 19);
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// beq cr6,0x8290df54
	if (ctx.cr6.eq) goto loc_8290DF54;
	// cmpwi cr6,r22,0
	ctx.cr6.compare<int32_t>(ctx.r22.s32, 0, ctx.xer);
	// beq cr6,0x8290ea68
	if (ctx.cr6.eq) goto loc_8290EA68;
	// lbz r10,1065(r18)
	ctx.r10.u64 = REX_LOAD_U8(ctx.r18.u32 + 1065);
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// beq cr6,0x8290dce0
	if (ctx.cr6.eq) goto loc_8290DCE0;
	// rlwinm r11,r11,20,12,31
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 20) & 0xFFFFF;
	// and r11,r11,r10
	ctx.r11.u64 = ctx.r11.u64 & ctx.r10.u64;
	// clrlwi r11,r11,28
	ctx.r11.u64 = ctx.r11.u32 & 0xF;
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x8290dccc
	if (ctx.cr6.eq) goto loc_8290DCCC;
	// lbz r11,1066(r18)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r18.u32 + 1066);
	// rotlwi r11,r11,1
	ctx.r11.u64 = __builtin_rotateleft32(ctx.r11.u32, 1);
	// b 0x8290df38
	goto loc_8290DF38;
loc_8290DCCC:
	// lbz r11,1064(r18)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r18.u32 + 1064);
	// lbz r10,1069(r18)
	ctx.r10.u64 = REX_LOAD_U8(ctx.r18.u32 + 1069);
	// rotlwi r11,r11,1
	ctx.r11.u64 = __builtin_rotateleft32(ctx.r11.u32, 1);
	// add r11,r11,r10
	ctx.r11.u64 = ctx.r11.u64 + ctx.r10.u64;
	// b 0x8290df38
	goto loc_8290DF38;
loc_8290DCE0:
	// lwz r31,0(r18)
	ctx.r31.u64 = REX_LOAD_U32(ctx.r18.u32 + 0);
	// mr r29,r14
	ctx.r29.u64 = ctx.r14.u64;
	// lbz r11,1070(r18)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r18.u32 + 1070);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// lwz r9,8(r31)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r31.u32 + 8);
	// addi r11,r9,16
	ctx.r11.s64 = ctx.r9.s64 + 16;
	// beq cr6,0x8290ddcc
	if (ctx.cr6.eq) goto loc_8290DDCC;
	// li r30,1
	ctx.r30.s64 = 1;
	// cmplwi cr6,r11,1
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 1, ctx.xer);
	// bge cr6,0x8290dd60
	if (!ctx.cr6.lt) goto loc_8290DD60;
loc_8290DD08:
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x8290dd60
	if (ctx.cr6.eq) goto loc_8290DD60;
	// subfic r8,r11,64
	ctx.xer.ca = ctx.r11.u32 <= 64;
	ctx.r8.u64 = static_cast<uint64_t>(64) - ctx.r11.u64;
	// ld r10,0(r31)
	ctx.r10.u64 = REX_LOAD_U64(ctx.r31.u32 + 0);
	// subf. r9,r11,r9
	ctx.r9.u64 = ctx.r9.u64 - ctx.r11.u64;
	ctx.cr0.compare<int32_t>(ctx.r9.s32, 0, ctx.xer);
	// clrldi r8,r8,32
	ctx.r8.u64 = ctx.r8.u64 & 0xFFFFFFFF;
	// subf r30,r11,r30
	ctx.r30.u64 = ctx.r30.u64 - ctx.r11.u64;
	// clrldi r11,r11,32
	ctx.r11.u64 = ctx.r11.u64 & 0xFFFFFFFF;
	// stw r9,8(r31)
	REX_STORE_U32(ctx.r31.u32 + 8, ctx.r9.u32);
	// srd r8,r10,r8
	ctx.r8.u64 = ctx.r8.u8 & 0x40 ? 0 : (ctx.r10.u64 >> (ctx.r8.u8 & 0x7F));
	// sld r11,r10,r11
	ctx.r11.u64 = ctx.r11.u8 & 0x40 ? 0 : (ctx.r10.u64 << (ctx.r11.u8 & 0x7F));
	// rotlwi r10,r8,0
	ctx.r10.u64 = __builtin_rotateleft32(ctx.r8.u32, 0);
	// std r11,0(r31)
	REX_STORE_U64(ctx.r31.u32 + 0, ctx.r11.u64);
	// slw r11,r10,r30
	ctx.r11.u64 = ctx.r30.u8 & 0x20 ? 0 : (ctx.r10.u32 << (ctx.r30.u8 & 0x3F));
	// add r29,r11,r29
	ctx.r29.u64 = ctx.r11.u64 + ctx.r29.u64;
	// bge 0x8290dd50
	if (!ctx.cr0.lt) goto loc_8290DD50;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x824c44e8
	ctx.lr = 0x8290DD50;
	sub_824C44E8(ctx, base);
loc_8290DD50:
	// lwz r9,8(r31)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r31.u32 + 8);
	// addi r11,r9,16
	ctx.r11.s64 = ctx.r9.s64 + 16;
	// cmplw cr6,r30,r11
	ctx.cr6.compare<uint32_t>(ctx.r30.u32, ctx.r11.u32, ctx.xer);
	// bgt cr6,0x8290dd08
	if (ctx.cr6.gt) goto loc_8290DD08;
loc_8290DD60:
	// subfic r9,r30,64
	ctx.xer.ca = ctx.r30.u32 <= 64;
	ctx.r9.u64 = static_cast<uint64_t>(64) - ctx.r30.u64;
	// ld r11,0(r31)
	ctx.r11.u64 = REX_LOAD_U64(ctx.r31.u32 + 0);
	// clrldi r8,r30,32
	ctx.r8.u64 = ctx.r30.u64 & 0xFFFFFFFF;
	// lwz r10,8(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 8);
	// clrldi r9,r9,32
	ctx.r9.u64 = ctx.r9.u64 & 0xFFFFFFFF;
	// subf. r10,r30,r10
	ctx.r10.u64 = ctx.r10.u64 - ctx.r30.u64;
	ctx.cr0.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// stw r10,8(r31)
	REX_STORE_U32(ctx.r31.u32 + 8, ctx.r10.u32);
	// sld r8,r11,r8
	ctx.r8.u64 = ctx.r8.u8 & 0x40 ? 0 : (ctx.r11.u64 << (ctx.r8.u8 & 0x7F));
	// srd r9,r11,r9
	ctx.r9.u64 = ctx.r9.u8 & 0x40 ? 0 : (ctx.r11.u64 >> (ctx.r9.u8 & 0x7F));
	// rotlwi r11,r9,0
	ctx.r11.u64 = __builtin_rotateleft32(ctx.r9.u32, 0);
	// add r30,r11,r29
	ctx.r30.u64 = ctx.r11.u64 + ctx.r29.u64;
	// std r8,0(r31)
	REX_STORE_U64(ctx.r31.u32 + 0, ctx.r8.u64);
	// bge 0x8290dd9c
	if (!ctx.cr0.lt) goto loc_8290DD9C;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x824c44e8
	ctx.lr = 0x8290DD9C;
	sub_824C44E8(ctx, base);
loc_8290DD9C:
	// cmplwi cr6,r30,0
	ctx.cr6.compare<uint32_t>(ctx.r30.u32, 0, ctx.xer);
	// beq cr6,0x8290ddb4
	if (ctx.cr6.eq) goto loc_8290DDB4;
	// lbz r11,1066(r18)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r18.u32 + 1066);
	// rotlwi r11,r11,1
	ctx.r11.u64 = __builtin_rotateleft32(ctx.r11.u32, 1);
	// addi r11,r11,-1
	ctx.r11.s64 = ctx.r11.s64 + -1;
	// b 0x8290df3c
	goto loc_8290DF3C;
loc_8290DDB4:
	// lbz r11,1064(r18)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r18.u32 + 1064);
	// lbz r10,1069(r18)
	ctx.r10.u64 = REX_LOAD_U8(ctx.r18.u32 + 1069);
	// rotlwi r11,r11,1
	ctx.r11.u64 = __builtin_rotateleft32(ctx.r11.u32, 1);
	// add r11,r11,r10
	ctx.r11.u64 = ctx.r11.u64 + ctx.r10.u64;
	// addi r11,r11,-1
	ctx.r11.s64 = ctx.r11.s64 + -1;
	// b 0x8290df3c
	goto loc_8290DF3C;
loc_8290DDCC:
	// li r30,3
	ctx.r30.s64 = 3;
	// cmplwi cr6,r11,3
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 3, ctx.xer);
	// bge cr6,0x8290de30
	if (!ctx.cr6.lt) goto loc_8290DE30;
loc_8290DDD8:
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x8290de30
	if (ctx.cr6.eq) goto loc_8290DE30;
	// subfic r8,r11,64
	ctx.xer.ca = ctx.r11.u32 <= 64;
	ctx.r8.u64 = static_cast<uint64_t>(64) - ctx.r11.u64;
	// ld r10,0(r31)
	ctx.r10.u64 = REX_LOAD_U64(ctx.r31.u32 + 0);
	// subf. r9,r11,r9
	ctx.r9.u64 = ctx.r9.u64 - ctx.r11.u64;
	ctx.cr0.compare<int32_t>(ctx.r9.s32, 0, ctx.xer);
	// clrldi r8,r8,32
	ctx.r8.u64 = ctx.r8.u64 & 0xFFFFFFFF;
	// subf r30,r11,r30
	ctx.r30.u64 = ctx.r30.u64 - ctx.r11.u64;
	// clrldi r11,r11,32
	ctx.r11.u64 = ctx.r11.u64 & 0xFFFFFFFF;
	// stw r9,8(r31)
	REX_STORE_U32(ctx.r31.u32 + 8, ctx.r9.u32);
	// srd r8,r10,r8
	ctx.r8.u64 = ctx.r8.u8 & 0x40 ? 0 : (ctx.r10.u64 >> (ctx.r8.u8 & 0x7F));
	// sld r11,r10,r11
	ctx.r11.u64 = ctx.r11.u8 & 0x40 ? 0 : (ctx.r10.u64 << (ctx.r11.u8 & 0x7F));
	// rotlwi r10,r8,0
	ctx.r10.u64 = __builtin_rotateleft32(ctx.r8.u32, 0);
	// std r11,0(r31)
	REX_STORE_U64(ctx.r31.u32 + 0, ctx.r11.u64);
	// slw r11,r10,r30
	ctx.r11.u64 = ctx.r30.u8 & 0x20 ? 0 : (ctx.r10.u32 << (ctx.r30.u8 & 0x3F));
	// add r29,r11,r29
	ctx.r29.u64 = ctx.r11.u64 + ctx.r29.u64;
	// bge 0x8290de20
	if (!ctx.cr0.lt) goto loc_8290DE20;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x824c44e8
	ctx.lr = 0x8290DE20;
	sub_824C44E8(ctx, base);
loc_8290DE20:
	// lwz r9,8(r31)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r31.u32 + 8);
	// addi r11,r9,16
	ctx.r11.s64 = ctx.r9.s64 + 16;
	// cmplw cr6,r30,r11
	ctx.cr6.compare<uint32_t>(ctx.r30.u32, ctx.r11.u32, ctx.xer);
	// bgt cr6,0x8290ddd8
	if (ctx.cr6.gt) goto loc_8290DDD8;
loc_8290DE30:
	// subfic r9,r30,64
	ctx.xer.ca = ctx.r30.u32 <= 64;
	ctx.r9.u64 = static_cast<uint64_t>(64) - ctx.r30.u64;
	// ld r11,0(r31)
	ctx.r11.u64 = REX_LOAD_U64(ctx.r31.u32 + 0);
	// clrldi r8,r30,32
	ctx.r8.u64 = ctx.r30.u64 & 0xFFFFFFFF;
	// lwz r10,8(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 8);
	// clrldi r9,r9,32
	ctx.r9.u64 = ctx.r9.u64 & 0xFFFFFFFF;
	// subf. r10,r30,r10
	ctx.r10.u64 = ctx.r10.u64 - ctx.r30.u64;
	ctx.cr0.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// stw r10,8(r31)
	REX_STORE_U32(ctx.r31.u32 + 8, ctx.r10.u32);
	// sld r8,r11,r8
	ctx.r8.u64 = ctx.r8.u8 & 0x40 ? 0 : (ctx.r11.u64 << (ctx.r8.u8 & 0x7F));
	// srd r9,r11,r9
	ctx.r9.u64 = ctx.r9.u8 & 0x40 ? 0 : (ctx.r11.u64 >> (ctx.r9.u8 & 0x7F));
	// rotlwi r11,r9,0
	ctx.r11.u64 = __builtin_rotateleft32(ctx.r9.u32, 0);
	// add r30,r11,r29
	ctx.r30.u64 = ctx.r11.u64 + ctx.r29.u64;
	// std r8,0(r31)
	REX_STORE_U64(ctx.r31.u32 + 0, ctx.r8.u64);
	// bge 0x8290de6c
	if (!ctx.cr0.lt) goto loc_8290DE6C;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x824c44e8
	ctx.lr = 0x8290DE6C;
	sub_824C44E8(ctx, base);
loc_8290DE6C:
	// cmpwi cr6,r30,7
	ctx.cr6.compare<int32_t>(ctx.r30.s32, 7, ctx.xer);
	// bne cr6,0x8290df2c
	if (!ctx.cr6.eq) goto loc_8290DF2C;
	// lwz r31,0(r18)
	ctx.r31.u64 = REX_LOAD_U32(ctx.r18.u32 + 0);
	// li r30,5
	ctx.r30.s64 = 5;
	// mr r29,r14
	ctx.r29.u64 = ctx.r14.u64;
	// lwz r9,8(r31)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r31.u32 + 8);
	// addi r11,r9,16
	ctx.r11.s64 = ctx.r9.s64 + 16;
	// cmplwi cr6,r11,5
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 5, ctx.xer);
	// bge cr6,0x8290dee8
	if (!ctx.cr6.lt) goto loc_8290DEE8;
loc_8290DE90:
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x8290dee8
	if (ctx.cr6.eq) goto loc_8290DEE8;
	// subfic r8,r11,64
	ctx.xer.ca = ctx.r11.u32 <= 64;
	ctx.r8.u64 = static_cast<uint64_t>(64) - ctx.r11.u64;
	// ld r10,0(r31)
	ctx.r10.u64 = REX_LOAD_U64(ctx.r31.u32 + 0);
	// subf. r9,r11,r9
	ctx.r9.u64 = ctx.r9.u64 - ctx.r11.u64;
	ctx.cr0.compare<int32_t>(ctx.r9.s32, 0, ctx.xer);
	// clrldi r8,r8,32
	ctx.r8.u64 = ctx.r8.u64 & 0xFFFFFFFF;
	// subf r30,r11,r30
	ctx.r30.u64 = ctx.r30.u64 - ctx.r11.u64;
	// clrldi r11,r11,32
	ctx.r11.u64 = ctx.r11.u64 & 0xFFFFFFFF;
	// stw r9,8(r31)
	REX_STORE_U32(ctx.r31.u32 + 8, ctx.r9.u32);
	// srd r8,r10,r8
	ctx.r8.u64 = ctx.r8.u8 & 0x40 ? 0 : (ctx.r10.u64 >> (ctx.r8.u8 & 0x7F));
	// sld r11,r10,r11
	ctx.r11.u64 = ctx.r11.u8 & 0x40 ? 0 : (ctx.r10.u64 << (ctx.r11.u8 & 0x7F));
	// rotlwi r10,r8,0
	ctx.r10.u64 = __builtin_rotateleft32(ctx.r8.u32, 0);
	// std r11,0(r31)
	REX_STORE_U64(ctx.r31.u32 + 0, ctx.r11.u64);
	// slw r11,r10,r30
	ctx.r11.u64 = ctx.r30.u8 & 0x20 ? 0 : (ctx.r10.u32 << (ctx.r30.u8 & 0x3F));
	// add r29,r11,r29
	ctx.r29.u64 = ctx.r11.u64 + ctx.r29.u64;
	// bge 0x8290ded8
	if (!ctx.cr0.lt) goto loc_8290DED8;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x824c44e8
	ctx.lr = 0x8290DED8;
	sub_824C44E8(ctx, base);
loc_8290DED8:
	// lwz r9,8(r31)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r31.u32 + 8);
	// addi r11,r9,16
	ctx.r11.s64 = ctx.r9.s64 + 16;
	// cmplw cr6,r30,r11
	ctx.cr6.compare<uint32_t>(ctx.r30.u32, ctx.r11.u32, ctx.xer);
	// bgt cr6,0x8290de90
	if (ctx.cr6.gt) goto loc_8290DE90;
loc_8290DEE8:
	// subfic r9,r30,64
	ctx.xer.ca = ctx.r30.u32 <= 64;
	ctx.r9.u64 = static_cast<uint64_t>(64) - ctx.r30.u64;
	// ld r11,0(r31)
	ctx.r11.u64 = REX_LOAD_U64(ctx.r31.u32 + 0);
	// clrldi r8,r30,32
	ctx.r8.u64 = ctx.r30.u64 & 0xFFFFFFFF;
	// lwz r10,8(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 8);
	// clrldi r9,r9,32
	ctx.r9.u64 = ctx.r9.u64 & 0xFFFFFFFF;
	// subf. r10,r30,r10
	ctx.r10.u64 = ctx.r10.u64 - ctx.r30.u64;
	ctx.cr0.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// stw r10,8(r31)
	REX_STORE_U32(ctx.r31.u32 + 8, ctx.r10.u32);
	// sld r8,r11,r8
	ctx.r8.u64 = ctx.r8.u8 & 0x40 ? 0 : (ctx.r11.u64 << (ctx.r8.u8 & 0x7F));
	// srd r9,r11,r9
	ctx.r9.u64 = ctx.r9.u8 & 0x40 ? 0 : (ctx.r11.u64 >> (ctx.r9.u8 & 0x7F));
	// rotlwi r11,r9,0
	ctx.r11.u64 = __builtin_rotateleft32(ctx.r9.u32, 0);
	// add r30,r11,r29
	ctx.r30.u64 = ctx.r11.u64 + ctx.r29.u64;
	// std r8,0(r31)
	REX_STORE_U64(ctx.r31.u32 + 0, ctx.r8.u64);
	// bge 0x8290df24
	if (!ctx.cr0.lt) goto loc_8290DF24;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x824c44e8
	ctx.lr = 0x8290DF24;
	sub_824C44E8(ctx, base);
loc_8290DF24:
	// mr r11,r30
	ctx.r11.u64 = ctx.r30.u64;
	// b 0x8290df34
	goto loc_8290DF34;
loc_8290DF2C:
	// lbz r11,1064(r18)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r18.u32 + 1064);
	// add r11,r11,r30
	ctx.r11.u64 = ctx.r11.u64 + ctx.r30.u64;
loc_8290DF34:
	// rlwinm r11,r11,1,0,30
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 1) & 0xFFFFFFFE;
loc_8290DF38:
	// addi r11,r11,255
	ctx.r11.s64 = ctx.r11.s64 + 255;
loc_8290DF3C:
	// stb r11,4(r17)
	REX_STORE_U8(ctx.r17.u32 + 4, ctx.r11.u8);
	// clrlwi r11,r11,24
	ctx.r11.u64 = ctx.r11.u32 & 0xFF;
	// cmplwi cr6,r11,1
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 1, ctx.xer);
	// blt cr6,0x8290e834
	if (ctx.cr6.lt) goto loc_8290E834;
	// cmplwi cr6,r11,62
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 62, ctx.xer);
	// bgt cr6,0x8290e834
	if (ctx.cr6.gt) goto loc_8290E834;
loc_8290DF54:
	// cmpwi cr6,r22,0
	ctx.cr6.compare<int32_t>(ctx.r22.s32, 0, ctx.xer);
	// beq cr6,0x8290ea68
	if (ctx.cr6.eq) goto loc_8290EA68;
	// lwz r3,0(r18)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r18.u32 + 0);
	// ld r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U64(ctx.r3.u32 + 0);
	// lwz r10,8(r3)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r3.u32 + 8);
	// rldicr r9,r11,1,62
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r11.u64, 1) & 0xFFFFFFFFFFFFFFFE;
	// rldicl r8,r11,1,63
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r11.u64, 1) & 0x1;
	// addic. r11,r10,-1
	ctx.xer.ca = ctx.r10.u32 > 0;
	ctx.r11.s64 = ctx.r10.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// rotlwi r31,r8,0
	ctx.r31.u64 = __builtin_rotateleft32(ctx.r8.u32, 0);
	// std r9,0(r3)
	REX_STORE_U64(ctx.r3.u32 + 0, ctx.r9.u64);
	// stw r11,8(r3)
	REX_STORE_U32(ctx.r3.u32 + 8, ctx.r11.u32);
	// bge 0x8290df88
	if (!ctx.cr0.lt) goto loc_8290DF88;
	// bl 0x824c44e8
	ctx.lr = 0x8290DF88;
	sub_824C44E8(ctx, base);
loc_8290DF88:
	// lwz r10,0(r17)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r17.u32 + 0);
	// clrlwi r11,r31,24
	ctx.r11.u64 = ctx.r31.u32 & 0xFF;
	// rlwimi r10,r11,3,27,28
	ctx.r10.u64 = (__builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 3) & 0x18) | (ctx.r10.u64 & 0xFFFFFFFFFFFFFFE7);
	// stw r10,0(r17)
	REX_STORE_U32(ctx.r17.u32 + 0, ctx.r10.u32);
	// b 0x8290ea68
	goto loc_8290EA68;
loc_8290DF9C:
	// rlwinm r11,r11,0,24,26
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 0) & 0xE0;
	// cmplwi cr6,r11,64
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 64, ctx.xer);
	// bne cr6,0x8290e3b8
	if (!ctx.cr6.eq) goto loc_8290E3B8;
	// lwz r31,0(r18)
	ctx.r31.u64 = REX_LOAD_U32(ctx.r18.u32 + 0);
	// lwz r11,100(r18)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r18.u32 + 100);
	// ld r9,0(r31)
	ctx.r9.u64 = REX_LOAD_U64(ctx.r31.u32 + 0);
	// lwz r28,0(r11)
	ctx.r28.u64 = REX_LOAD_U32(ctx.r11.u32 + 0);
	// rldicl r11,r9,10,54
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r9.u64, 10) & 0x3FF;
	// rlwinm r11,r11,1,0,30
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 1) & 0xFFFFFFFE;
	// lhzx r11,r11,r28
	ctx.r11.u64 = REX_LOAD_U16(ctx.r11.u32 + ctx.r28.u32);
	// extsh r30,r11
	ctx.r30.s64 = ctx.r11.s16;
	// cmpwi cr6,r30,0
	ctx.cr6.compare<int32_t>(ctx.r30.s32, 0, ctx.xer);
	// blt cr6,0x8290e090
	if (ctx.cr6.lt) goto loc_8290E090;
	// clrlwi r11,r30,28
	ctx.r11.u64 = ctx.r30.u32 & 0xF;
	// lwz r10,8(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 8);
	// cmpw cr6,r10,r11
	ctx.cr6.compare<int32_t>(ctx.r10.s32, ctx.r11.s32, ctx.xer);
	// sld r9,r9,r11
	ctx.r9.u64 = ctx.r11.u8 & 0x40 ? 0 : (ctx.r9.u64 << (ctx.r11.u8 & 0x7F));
	// std r9,0(r31)
	REX_STORE_U64(ctx.r31.u32 + 0, ctx.r9.u64);
	// subf r9,r11,r10
	ctx.r9.u64 = ctx.r10.u64 - ctx.r11.u64;
	// stw r9,8(r31)
	REX_STORE_U32(ctx.r31.u32 + 8, ctx.r9.u32);
	// bge cr6,0x8290e088
	if (!ctx.cr6.lt) goto loc_8290E088;
loc_8290DFF0:
	// lwz r10,16(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 16);
	// lwz r11,12(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 12);
	// addi r10,r10,-4
	ctx.r10.s64 = ctx.r10.s64 + -4;
	// cmplw cr6,r11,r10
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, ctx.r10.u32, ctx.xer);
	// blt cr6,0x8290e01c
	if (ctx.cr6.lt) goto loc_8290E01C;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x824c4428
	ctx.lr = 0x8290E00C;
	sub_824C4428(ctx, base);
	// cmplwi cr6,r3,1
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 1, ctx.xer);
	// beq cr6,0x8290dff0
	if (ctx.cr6.eq) goto loc_8290DFF0;
	// srawi r30,r30,4
	ctx.xer.ca = (ctx.r30.s32 < 0) & ((ctx.r30.u32 & 0xF) != 0);
	ctx.r30.s64 = ctx.r30.s32 >> 4;
	// b 0x8290e0d0
	goto loc_8290E0D0;
loc_8290E01C:
	// lbz r8,0(r11)
	ctx.r8.u64 = REX_LOAD_U8(ctx.r11.u32 + 0);
	// addi r4,r11,6
	ctx.r4.s64 = ctx.r11.s64 + 6;
	// lbz r9,1(r11)
	ctx.r9.u64 = REX_LOAD_U8(ctx.r11.u32 + 1);
	// rldicr r8,r8,8,63
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r8.u64, 8) & 0xFFFFFFFFFFFFFFFF;
	// lbz r5,2(r11)
	ctx.r5.u64 = REX_LOAD_U8(ctx.r11.u32 + 2);
	// lbz r6,3(r11)
	ctx.r6.u64 = REX_LOAD_U8(ctx.r11.u32 + 3);
	// add r9,r9,r8
	ctx.r9.u64 = ctx.r9.u64 + ctx.r8.u64;
	// lbz r8,5(r11)
	ctx.r8.u64 = REX_LOAD_U8(ctx.r11.u32 + 5);
	// lbz r7,4(r11)
	ctx.r7.u64 = REX_LOAD_U8(ctx.r11.u32 + 4);
	// rldicr r11,r9,8,55
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r9.u64, 8) & 0xFFFFFFFFFFFFFF00;
	// lwz r10,8(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 8);
	// ld r9,0(r31)
	ctx.r9.u64 = REX_LOAD_U64(ctx.r31.u32 + 0);
	// add r11,r11,r5
	ctx.r11.u64 = ctx.r11.u64 + ctx.r5.u64;
	// stw r4,12(r31)
	REX_STORE_U32(ctx.r31.u32 + 12, ctx.r4.u32);
	// rldicr r11,r11,8,55
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u64, 8) & 0xFFFFFFFFFFFFFF00;
	// add r11,r11,r6
	ctx.r11.u64 = ctx.r11.u64 + ctx.r6.u64;
	// rldicr r11,r11,8,55
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u64, 8) & 0xFFFFFFFFFFFFFF00;
	// add r11,r11,r7
	ctx.r11.u64 = ctx.r11.u64 + ctx.r7.u64;
	// rldicr r11,r11,8,55
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u64, 8) & 0xFFFFFFFFFFFFFF00;
	// add r11,r11,r8
	ctx.r11.u64 = ctx.r11.u64 + ctx.r8.u64;
	// neg r8,r10
	ctx.r8.s64 = static_cast<int64_t>(-ctx.r10.u64);
	// addi r10,r10,48
	ctx.r10.s64 = ctx.r10.s64 + 48;
	// extsw r8,r8
	ctx.r8.s64 = ctx.r8.s32;
	// stw r10,8(r31)
	REX_STORE_U32(ctx.r31.u32 + 8, ctx.r10.u32);
	// sld r11,r11,r8
	ctx.r11.u64 = ctx.r8.u8 & 0x40 ? 0 : (ctx.r11.u64 << (ctx.r8.u8 & 0x7F));
	// add r11,r11,r9
	ctx.r11.u64 = ctx.r11.u64 + ctx.r9.u64;
	// std r11,0(r31)
	REX_STORE_U64(ctx.r31.u32 + 0, ctx.r11.u64);
loc_8290E088:
	// srawi r30,r30,4
	ctx.xer.ca = (ctx.r30.s32 < 0) & ((ctx.r30.u32 & 0xF) != 0);
	ctx.r30.s64 = ctx.r30.s32 >> 4;
	// b 0x8290e0d0
	goto loc_8290E0D0;
loc_8290E090:
	// li r4,10
	ctx.r4.s64 = 10;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x824c45b8
	ctx.lr = 0x8290E09C;
	sub_824C45B8(ctx, base);
loc_8290E09C:
	// ld r11,0(r31)
	ctx.r11.u64 = REX_LOAD_U64(ctx.r31.u32 + 0);
	// li r4,1
	ctx.r4.s64 = 1;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// rldicl r11,r11,1,63
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u64, 1) & 0x1;
	// rotlwi r29,r11,0
	ctx.r29.u64 = __builtin_rotateleft32(ctx.r11.u32, 0);
	// bl 0x824c45b8
	ctx.lr = 0x8290E0B4;
	sub_824C45B8(ctx, base);
	// add r11,r30,r29
	ctx.r11.u64 = ctx.r30.u64 + ctx.r29.u64;
	// add r11,r11,r15
	ctx.r11.u64 = ctx.r11.u64 + ctx.r15.u64;
	// rlwinm r11,r11,1,0,30
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 1) & 0xFFFFFFFE;
	// lhzx r11,r11,r28
	ctx.r11.u64 = REX_LOAD_U16(ctx.r11.u32 + ctx.r28.u32);
	// extsh r30,r11
	ctx.r30.s64 = ctx.r11.s16;
	// cmpwi cr6,r30,0
	ctx.cr6.compare<int32_t>(ctx.r30.s32, 0, ctx.xer);
	// blt cr6,0x8290e09c
	if (ctx.cr6.lt) goto loc_8290E09C;
loc_8290E0D0:
	// addi r11,r30,1
	ctx.r11.s64 = ctx.r30.s64 + 1;
	// li r10,1
	ctx.r10.s64 = 1;
	// cmpwi cr6,r11,37
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 37, ctx.xer);
	// bge cr6,0x8290e0e4
	if (!ctx.cr6.lt) goto loc_8290E0E4;
	// mr r10,r14
	ctx.r10.u64 = ctx.r14.u64;
loc_8290E0E4:
	// extsw r23,r10
	ctx.r23.s64 = ctx.r10.s32;
	// cmpwi cr6,r10,0
	ctx.cr6.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// beq cr6,0x8290e0f4
	if (ctx.cr6.eq) goto loc_8290E0F4;
	// addi r11,r11,-37
	ctx.r11.s64 = ctx.r11.s64 + -37;
loc_8290E0F4:
	// mr r24,r14
	ctx.r24.u64 = ctx.r14.u64;
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// bne cr6,0x8290e108
	if (!ctx.cr6.eq) goto loc_8290E108;
	// mr r11,r14
	ctx.r11.u64 = ctx.r14.u64;
	// b 0x8290e370
	goto loc_8290E370;
loc_8290E108:
	// cmpwi cr6,r11,35
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 35, ctx.xer);
	// bge cr6,0x8290e258
	if (!ctx.cr6.lt) goto loc_8290E258;
	// lwz r10,12(r18)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r18.u32 + 12);
	// rlwinm r11,r11,2,0,29
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r11,r11,r10
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + ctx.r10.u32);
	// srawi r9,r11,24
	ctx.xer.ca = (ctx.r11.s32 < 0) & ((ctx.r11.u32 & 0xFFFFFF) != 0);
	ctx.r9.s64 = ctx.r11.s32 >> 24;
	// srawi r8,r11,4
	ctx.xer.ca = (ctx.r11.s32 < 0) & ((ctx.r11.u32 & 0xF) != 0);
	ctx.r8.s64 = ctx.r11.s32 >> 4;
	// clrlwi r10,r11,28
	ctx.r10.u64 = ctx.r11.u32 & 0xF;
	// clrlwi r28,r8,28
	ctx.r28.u64 = ctx.r8.u32 & 0xF;
	// srawi r8,r11,8
	ctx.xer.ca = (ctx.r11.s32 < 0) & ((ctx.r11.u32 & 0xFF) != 0);
	ctx.r8.s64 = ctx.r11.s32 >> 8;
	// srawi r11,r11,16
	ctx.xer.ca = (ctx.r11.s32 < 0) & ((ctx.r11.u32 & 0xFFFF) != 0);
	ctx.r11.s64 = ctx.r11.s32 >> 16;
	// add r30,r10,r28
	ctx.r30.u64 = ctx.r10.u64 + ctx.r28.u64;
	// clrlwi r27,r9,24
	ctx.r27.u64 = ctx.r9.u32 & 0xFF;
	// clrlwi r26,r8,24
	ctx.r26.u64 = ctx.r8.u32 & 0xFF;
	// clrlwi r25,r11,24
	ctx.r25.u64 = ctx.r11.u32 & 0xFF;
	// cmpwi cr6,r30,0
	ctx.cr6.compare<int32_t>(ctx.r30.s32, 0, ctx.xer);
	// ble cr6,0x8290e204
	if (!ctx.cr6.gt) goto loc_8290E204;
	// lwz r9,8(r31)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r31.u32 + 8);
	// mr r29,r14
	ctx.r29.u64 = ctx.r14.u64;
	// cmplwi cr6,r30,0
	ctx.cr6.compare<uint32_t>(ctx.r30.u32, 0, ctx.xer);
	// addi r11,r9,16
	ctx.r11.s64 = ctx.r9.s64 + 16;
	// beq cr6,0x8290e204
	if (ctx.cr6.eq) goto loc_8290E204;
	// cmplw cr6,r30,r11
	ctx.cr6.compare<uint32_t>(ctx.r30.u32, ctx.r11.u32, ctx.xer);
	// ble cr6,0x8290e1c0
	if (!ctx.cr6.gt) goto loc_8290E1C0;
loc_8290E168:
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x8290e1c0
	if (ctx.cr6.eq) goto loc_8290E1C0;
	// subfic r8,r11,64
	ctx.xer.ca = ctx.r11.u32 <= 64;
	ctx.r8.u64 = static_cast<uint64_t>(64) - ctx.r11.u64;
	// ld r10,0(r31)
	ctx.r10.u64 = REX_LOAD_U64(ctx.r31.u32 + 0);
	// subf. r9,r11,r9
	ctx.r9.u64 = ctx.r9.u64 - ctx.r11.u64;
	ctx.cr0.compare<int32_t>(ctx.r9.s32, 0, ctx.xer);
	// clrldi r8,r8,32
	ctx.r8.u64 = ctx.r8.u64 & 0xFFFFFFFF;
	// subf r30,r11,r30
	ctx.r30.u64 = ctx.r30.u64 - ctx.r11.u64;
	// clrldi r11,r11,32
	ctx.r11.u64 = ctx.r11.u64 & 0xFFFFFFFF;
	// stw r9,8(r31)
	REX_STORE_U32(ctx.r31.u32 + 8, ctx.r9.u32);
	// srd r8,r10,r8
	ctx.r8.u64 = ctx.r8.u8 & 0x40 ? 0 : (ctx.r10.u64 >> (ctx.r8.u8 & 0x7F));
	// sld r11,r10,r11
	ctx.r11.u64 = ctx.r11.u8 & 0x40 ? 0 : (ctx.r10.u64 << (ctx.r11.u8 & 0x7F));
	// rotlwi r10,r8,0
	ctx.r10.u64 = __builtin_rotateleft32(ctx.r8.u32, 0);
	// std r11,0(r31)
	REX_STORE_U64(ctx.r31.u32 + 0, ctx.r11.u64);
	// slw r11,r10,r30
	ctx.r11.u64 = ctx.r30.u8 & 0x20 ? 0 : (ctx.r10.u32 << (ctx.r30.u8 & 0x3F));
	// add r29,r11,r29
	ctx.r29.u64 = ctx.r11.u64 + ctx.r29.u64;
	// bge 0x8290e1b0
	if (!ctx.cr0.lt) goto loc_8290E1B0;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x824c44e8
	ctx.lr = 0x8290E1B0;
	sub_824C44E8(ctx, base);
loc_8290E1B0:
	// lwz r9,8(r31)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r31.u32 + 8);
	// addi r11,r9,16
	ctx.r11.s64 = ctx.r9.s64 + 16;
	// cmplw cr6,r30,r11
	ctx.cr6.compare<uint32_t>(ctx.r30.u32, ctx.r11.u32, ctx.xer);
	// bgt cr6,0x8290e168
	if (ctx.cr6.gt) goto loc_8290E168;
loc_8290E1C0:
	// subfic r9,r30,64
	ctx.xer.ca = ctx.r30.u32 <= 64;
	ctx.r9.u64 = static_cast<uint64_t>(64) - ctx.r30.u64;
	// ld r11,0(r31)
	ctx.r11.u64 = REX_LOAD_U64(ctx.r31.u32 + 0);
	// clrldi r8,r30,32
	ctx.r8.u64 = ctx.r30.u64 & 0xFFFFFFFF;
	// lwz r10,8(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 8);
	// clrldi r9,r9,32
	ctx.r9.u64 = ctx.r9.u64 & 0xFFFFFFFF;
	// subf. r10,r30,r10
	ctx.r10.u64 = ctx.r10.u64 - ctx.r30.u64;
	ctx.cr0.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// stw r10,8(r31)
	REX_STORE_U32(ctx.r31.u32 + 8, ctx.r10.u32);
	// sld r8,r11,r8
	ctx.r8.u64 = ctx.r8.u8 & 0x40 ? 0 : (ctx.r11.u64 << (ctx.r8.u8 & 0x7F));
	// srd r9,r11,r9
	ctx.r9.u64 = ctx.r9.u8 & 0x40 ? 0 : (ctx.r11.u64 >> (ctx.r9.u8 & 0x7F));
	// rotlwi r11,r9,0
	ctx.r11.u64 = __builtin_rotateleft32(ctx.r9.u32, 0);
	// add r30,r11,r29
	ctx.r30.u64 = ctx.r11.u64 + ctx.r29.u64;
	// std r8,0(r31)
	REX_STORE_U64(ctx.r31.u32 + 0, ctx.r8.u64);
	// bge 0x8290e1fc
	if (!ctx.cr0.lt) goto loc_8290E1FC;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x824c44e8
	ctx.lr = 0x8290E1FC;
	sub_824C44E8(ctx, base);
loc_8290E1FC:
	// mr r10,r30
	ctx.r10.u64 = ctx.r30.u64;
	// b 0x8290e208
	goto loc_8290E208;
loc_8290E204:
	// mr r10,r14
	ctx.r10.u64 = ctx.r14.u64;
loc_8290E208:
	// and r11,r10,r27
	ctx.r11.u64 = ctx.r10.u64 & ctx.r27.u64;
	// rlwinm r8,r25,1,0,30
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r25.u32 | (ctx.r25.u64 << 32), 1) & 0xFFFFFFFE;
	// rlwinm r9,r11,0,0,30
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 0) & 0xFFFFFFFE;
	// sraw r10,r10,r28
	temp.u32 = ctx.r28.u32 & 0x3F;
	if (temp.u32 > 0x1F) temp.u32 = 0x1F;
	ctx.xer.ca = (ctx.r10.s32 < 0) & (((ctx.r10.s32 >> temp.u32) << temp.u32) != ctx.r10.s32);
	ctx.r10.s64 = ctx.r10.s32 >> temp.u32;
	// add r9,r9,r8
	ctx.r9.u64 = ctx.r9.u64 + ctx.r8.u64;
	// clrlwi r7,r11,31
	ctx.r7.u64 = ctx.r11.u32 & 0x1;
	// rlwinm r8,r9,15,0,16
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 15) & 0xFFFF8000;
	// clrlwi r9,r10,31
	ctx.r9.u64 = ctx.r10.u32 & 0x1;
	// srawi r10,r10,1
	ctx.xer.ca = (ctx.r10.s32 < 0) & ((ctx.r10.u32 & 0x1) != 0);
	ctx.r10.s64 = ctx.r10.s32 >> 1;
	// neg r11,r7
	ctx.r11.s64 = static_cast<int64_t>(-ctx.r7.u64);
	// add r10,r10,r26
	ctx.r10.u64 = ctx.r10.u64 + ctx.r26.u64;
	// neg r9,r9
	ctx.r9.s64 = static_cast<int64_t>(-ctx.r9.u64);
	// rlwinm r7,r11,16,0,15
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 16) & 0xFFFF0000;
	// xor r10,r10,r9
	ctx.r10.u64 = ctx.r10.u64 ^ ctx.r9.u64;
	// rlwinm r11,r11,16,0,15
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 16) & 0xFFFF0000;
	// xor r8,r8,r7
	ctx.r8.u64 = ctx.r8.u64 ^ ctx.r7.u64;
	// subf r10,r9,r10
	ctx.r10.u64 = ctx.r10.u64 - ctx.r9.u64;
	// subf r11,r11,r8
	ctx.r11.u64 = ctx.r8.u64 - ctx.r11.u64;
	// clrlwi r10,r10,16
	ctx.r10.u64 = ctx.r10.u32 & 0xFFFF;
	// b 0x8290e36c
	goto loc_8290E36C;
loc_8290E258:
	// cmpwi cr6,r11,36
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 36, ctx.xer);
	// bne cr6,0x8290e26c
	if (!ctx.cr6.eq) goto loc_8290E26C;
	// li r24,1
	ctx.r24.s64 = 1;
	// mr r11,r14
	ctx.r11.u64 = ctx.r14.u64;
	// b 0x8290e370
	goto loc_8290E370;
loc_8290E26C:
	// lbz r11,22(r18)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r18.u32 + 22);
	// mr r29,r14
	ctx.r29.u64 = ctx.r14.u64;
	// lhz r10,62(r18)
	ctx.r10.u64 = REX_LOAD_U16(ctx.r18.u32 + 62);
	// lhz r9,64(r18)
	ctx.r9.u64 = REX_LOAD_U16(ctx.r18.u32 + 64);
	// subf r27,r11,r10
	ctx.r27.u64 = ctx.r10.u64 - ctx.r11.u64;
	// lwz r10,8(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 8);
	// subf r28,r11,r9
	ctx.r28.u64 = ctx.r9.u64 - ctx.r11.u64;
	// addi r11,r10,16
	ctx.r11.s64 = ctx.r10.s64 + 16;
	// add r30,r28,r27
	ctx.r30.u64 = ctx.r28.u64 + ctx.r27.u64;
	// cmplwi cr6,r30,0
	ctx.cr6.compare<uint32_t>(ctx.r30.u32, 0, ctx.xer);
	// bne cr6,0x8290e2a0
	if (!ctx.cr6.eq) goto loc_8290E2A0;
	// mr r11,r14
	ctx.r11.u64 = ctx.r14.u64;
	// b 0x8290e340
	goto loc_8290E340;
loc_8290E2A0:
	// cmplw cr6,r30,r11
	ctx.cr6.compare<uint32_t>(ctx.r30.u32, ctx.r11.u32, ctx.xer);
	// ble cr6,0x8290e300
	if (!ctx.cr6.gt) goto loc_8290E300;
loc_8290E2A8:
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x8290e300
	if (ctx.cr6.eq) goto loc_8290E300;
	// subfic r8,r11,64
	ctx.xer.ca = ctx.r11.u32 <= 64;
	ctx.r8.u64 = static_cast<uint64_t>(64) - ctx.r11.u64;
	// ld r9,0(r31)
	ctx.r9.u64 = REX_LOAD_U64(ctx.r31.u32 + 0);
	// subf. r10,r11,r10
	ctx.r10.u64 = ctx.r10.u64 - ctx.r11.u64;
	ctx.cr0.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// clrldi r8,r8,32
	ctx.r8.u64 = ctx.r8.u64 & 0xFFFFFFFF;
	// subf r30,r11,r30
	ctx.r30.u64 = ctx.r30.u64 - ctx.r11.u64;
	// clrldi r11,r11,32
	ctx.r11.u64 = ctx.r11.u64 & 0xFFFFFFFF;
	// stw r10,8(r31)
	REX_STORE_U32(ctx.r31.u32 + 8, ctx.r10.u32);
	// srd r8,r9,r8
	ctx.r8.u64 = ctx.r8.u8 & 0x40 ? 0 : (ctx.r9.u64 >> (ctx.r8.u8 & 0x7F));
	// sld r11,r9,r11
	ctx.r11.u64 = ctx.r11.u8 & 0x40 ? 0 : (ctx.r9.u64 << (ctx.r11.u8 & 0x7F));
	// rotlwi r9,r8,0
	ctx.r9.u64 = __builtin_rotateleft32(ctx.r8.u32, 0);
	// std r11,0(r31)
	REX_STORE_U64(ctx.r31.u32 + 0, ctx.r11.u64);
	// slw r11,r9,r30
	ctx.r11.u64 = ctx.r30.u8 & 0x20 ? 0 : (ctx.r9.u32 << (ctx.r30.u8 & 0x3F));
	// add r29,r11,r29
	ctx.r29.u64 = ctx.r11.u64 + ctx.r29.u64;
	// bge 0x8290e2f0
	if (!ctx.cr0.lt) goto loc_8290E2F0;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x824c44e8
	ctx.lr = 0x8290E2F0;
	sub_824C44E8(ctx, base);
loc_8290E2F0:
	// lwz r10,8(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 8);
	// addi r11,r10,16
	ctx.r11.s64 = ctx.r10.s64 + 16;
	// cmplw cr6,r30,r11
	ctx.cr6.compare<uint32_t>(ctx.r30.u32, ctx.r11.u32, ctx.xer);
	// bgt cr6,0x8290e2a8
	if (ctx.cr6.gt) goto loc_8290E2A8;
loc_8290E300:
	// subfic r9,r30,64
	ctx.xer.ca = ctx.r30.u32 <= 64;
	ctx.r9.u64 = static_cast<uint64_t>(64) - ctx.r30.u64;
	// ld r11,0(r31)
	ctx.r11.u64 = REX_LOAD_U64(ctx.r31.u32 + 0);
	// clrldi r8,r30,32
	ctx.r8.u64 = ctx.r30.u64 & 0xFFFFFFFF;
	// lwz r10,8(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 8);
	// clrldi r9,r9,32
	ctx.r9.u64 = ctx.r9.u64 & 0xFFFFFFFF;
	// subf. r10,r30,r10
	ctx.r10.u64 = ctx.r10.u64 - ctx.r30.u64;
	ctx.cr0.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// stw r10,8(r31)
	REX_STORE_U32(ctx.r31.u32 + 8, ctx.r10.u32);
	// sld r8,r11,r8
	ctx.r8.u64 = ctx.r8.u8 & 0x40 ? 0 : (ctx.r11.u64 << (ctx.r8.u8 & 0x7F));
	// srd r9,r11,r9
	ctx.r9.u64 = ctx.r9.u8 & 0x40 ? 0 : (ctx.r11.u64 >> (ctx.r9.u8 & 0x7F));
	// rotlwi r11,r9,0
	ctx.r11.u64 = __builtin_rotateleft32(ctx.r9.u32, 0);
	// add r30,r11,r29
	ctx.r30.u64 = ctx.r11.u64 + ctx.r29.u64;
	// std r8,0(r31)
	REX_STORE_U64(ctx.r31.u32 + 0, ctx.r8.u64);
	// bge 0x8290e33c
	if (!ctx.cr0.lt) goto loc_8290E33C;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x824c44e8
	ctx.lr = 0x8290E33C;
	sub_824C44E8(ctx, base);
loc_8290E33C:
	// mr r11,r30
	ctx.r11.u64 = ctx.r30.u64;
loc_8290E340:
	// li r9,1
	ctx.r9.s64 = 1;
	// rlwinm r8,r11,16,0,15
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 16) & 0xFFFF0000;
	// sraw r11,r11,r28
	temp.u32 = ctx.r28.u32 & 0x3F;
	if (temp.u32 > 0x1F) temp.u32 = 0x1F;
	ctx.xer.ca = (ctx.r11.s32 < 0) & (((ctx.r11.s32 >> temp.u32) << temp.u32) != ctx.r11.s32);
	ctx.r11.s64 = ctx.r11.s32 >> temp.u32;
	// slw r10,r9,r27
	ctx.r10.u64 = ctx.r27.u8 & 0x20 ? 0 : (ctx.r9.u32 << (ctx.r27.u8 & 0x3F));
	// slw r9,r9,r28
	ctx.r9.u64 = ctx.r28.u8 & 0x20 ? 0 : (ctx.r9.u32 << (ctx.r28.u8 & 0x3F));
	// addi r10,r10,-1
	ctx.r10.s64 = ctx.r10.s64 + -1;
	// rlwinm r9,r9,16,0,15
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 16) & 0xFFFF0000;
	// and r11,r11,r10
	ctx.r11.u64 = ctx.r11.u64 & ctx.r10.u64;
	// addis r10,r9,-1
	ctx.r10.s64 = ctx.r9.s64 + -65536;
	// clrlwi r11,r11,16
	ctx.r11.u64 = ctx.r11.u32 & 0xFFFF;
	// and r10,r10,r8
	ctx.r10.u64 = ctx.r10.u64 & ctx.r8.u64;
loc_8290E36C:
	// or r11,r11,r10
	ctx.r11.u64 = ctx.r11.u64 | ctx.r10.u64;
loc_8290E370:
	// rldicr r10,r23,8,55
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r23.u64, 8) & 0xFFFFFFFFFFFFFF00;
	// clrldi r11,r11,32
	ctx.r11.u64 = ctx.r11.u64 & 0xFFFFFFFF;
	// or r10,r10,r24
	ctx.r10.u64 = ctx.r10.u64 | ctx.r24.u64;
	// rldicr r10,r10,32,31
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u64, 32) & 0xFFFFFFFF00000000;
	// or r11,r10,r11
	ctx.r11.u64 = ctx.r10.u64 | ctx.r11.u64;
	// rldicl r10,r11,32,32
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r11.u64, 32) & 0xFFFFFFFF;
	// rotlwi r20,r11,0
	ctx.r20.u64 = __builtin_rotateleft32(ctx.r11.u32, 0);
	// clrlwi r10,r10,31
	ctx.r10.u64 = ctx.r10.u32 & 0x1;
	// or r10,r10,r22
	ctx.r10.u64 = ctx.r10.u64 | ctx.r22.u64;
	// cmpwi cr6,r10,0
	ctx.cr6.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// bne cr6,0x8290e834
	if (!ctx.cr6.eq) goto loc_8290E834;
	// rldicl r11,r11,24,40
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u64, 24) & 0xFFFFFF;
	// clrlwi r11,r11,31
	ctx.r11.u64 = ctx.r11.u32 & 0x1;
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// bne cr6,0x8290e3b8
	if (!ctx.cr6.eq) goto loc_8290E3B8;
	// lwz r11,0(r17)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r17.u32 + 0);
	// oris r11,r11,16384
	ctx.r11.u64 = ctx.r11.u64 | 1073741824;
	// b 0x8290ea64
	goto loc_8290EA64;
loc_8290E3B8:
	// lbz r11,21(r18)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r18.u32 + 21);
	// lbz r27,20(r18)
	ctx.r27.u64 = REX_LOAD_U8(ctx.r18.u32 + 20);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x8290e3d8
	if (ctx.cr6.eq) goto loc_8290E3D8;
	// cmpwi cr6,r22,0
	ctx.cr6.compare<int32_t>(ctx.r22.s32, 0, ctx.xer);
	// bne cr6,0x8290e3d8
	if (!ctx.cr6.eq) goto loc_8290E3D8;
	// li r26,1
	ctx.r26.s64 = 1;
	// b 0x8290e420
	goto loc_8290E420;
loc_8290E3D8:
	// mr r26,r14
	ctx.r26.u64 = ctx.r14.u64;
	// cmpwi cr6,r22,0
	ctx.cr6.compare<int32_t>(ctx.r22.s32, 0, ctx.xer);
	// beq cr6,0x8290e420
	if (ctx.cr6.eq) goto loc_8290E420;
	// lwz r3,0(r18)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r18.u32 + 0);
	// ld r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U64(ctx.r3.u32 + 0);
	// lwz r10,8(r3)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r3.u32 + 8);
	// rldicr r9,r11,1,62
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r11.u64, 1) & 0xFFFFFFFFFFFFFFFE;
	// rldicl r8,r11,1,63
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r11.u64, 1) & 0x1;
	// addic. r11,r10,-1
	ctx.xer.ca = ctx.r10.u32 > 0;
	ctx.r11.s64 = ctx.r10.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// rotlwi r31,r8,0
	ctx.r31.u64 = __builtin_rotateleft32(ctx.r8.u32, 0);
	// std r9,0(r3)
	REX_STORE_U64(ctx.r3.u32 + 0, ctx.r9.u64);
	// stw r11,8(r3)
	REX_STORE_U32(ctx.r3.u32 + 8, ctx.r11.u32);
	// bge 0x8290e410
	if (!ctx.cr0.lt) goto loc_8290E410;
	// bl 0x824c44e8
	ctx.lr = 0x8290E410;
	sub_824C44E8(ctx, base);
loc_8290E410:
	// lwz r10,0(r17)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r17.u32 + 0);
	// clrlwi r11,r31,24
	ctx.r11.u64 = ctx.r31.u32 & 0xFF;
	// rlwimi r10,r11,3,27,28
	ctx.r10.u64 = (__builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 3) & 0x18) | (ctx.r10.u64 & 0xFFFFFFFFFFFFFFE7);
	// stw r10,0(r17)
	REX_STORE_U32(ctx.r17.u32 + 0, ctx.r10.u32);
loc_8290E420:
	// lwz r31,0(r18)
	ctx.r31.u64 = REX_LOAD_U32(ctx.r18.u32 + 0);
	// lwz r11,120(r18)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r18.u32 + 120);
	// ld r9,0(r31)
	ctx.r9.u64 = REX_LOAD_U64(ctx.r31.u32 + 0);
	// lwz r28,0(r11)
	ctx.r28.u64 = REX_LOAD_U32(ctx.r11.u32 + 0);
	// rldicl r11,r9,8,56
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r9.u64, 8) & 0xFF;
	// rlwinm r11,r11,1,0,30
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 1) & 0xFFFFFFFE;
	// lhzx r11,r11,r28
	ctx.r11.u64 = REX_LOAD_U16(ctx.r11.u32 + ctx.r28.u32);
	// extsh r30,r11
	ctx.r30.s64 = ctx.r11.s16;
	// cmpwi cr6,r30,0
	ctx.cr6.compare<int32_t>(ctx.r30.s32, 0, ctx.xer);
	// blt cr6,0x8290e508
	if (ctx.cr6.lt) goto loc_8290E508;
	// clrlwi r11,r30,28
	ctx.r11.u64 = ctx.r30.u32 & 0xF;
	// lwz r10,8(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 8);
	// cmpw cr6,r10,r11
	ctx.cr6.compare<int32_t>(ctx.r10.s32, ctx.r11.s32, ctx.xer);
	// sld r9,r9,r11
	ctx.r9.u64 = ctx.r11.u8 & 0x40 ? 0 : (ctx.r9.u64 << (ctx.r11.u8 & 0x7F));
	// std r9,0(r31)
	REX_STORE_U64(ctx.r31.u32 + 0, ctx.r9.u64);
	// subf r9,r11,r10
	ctx.r9.u64 = ctx.r10.u64 - ctx.r11.u64;
	// stw r9,8(r31)
	REX_STORE_U32(ctx.r31.u32 + 8, ctx.r9.u32);
	// bge cr6,0x8290e500
	if (!ctx.cr6.lt) goto loc_8290E500;
loc_8290E468:
	// lwz r10,16(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 16);
	// lwz r11,12(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 12);
	// addi r10,r10,-4
	ctx.r10.s64 = ctx.r10.s64 + -4;
	// cmplw cr6,r11,r10
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, ctx.r10.u32, ctx.xer);
	// blt cr6,0x8290e494
	if (ctx.cr6.lt) goto loc_8290E494;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x824c4428
	ctx.lr = 0x8290E484;
	sub_824C4428(ctx, base);
	// cmplwi cr6,r3,1
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 1, ctx.xer);
	// beq cr6,0x8290e468
	if (ctx.cr6.eq) goto loc_8290E468;
	// srawi r30,r30,4
	ctx.xer.ca = (ctx.r30.s32 < 0) & ((ctx.r30.u32 & 0xF) != 0);
	ctx.r30.s64 = ctx.r30.s32 >> 4;
	// b 0x8290e548
	goto loc_8290E548;
loc_8290E494:
	// lbz r8,0(r11)
	ctx.r8.u64 = REX_LOAD_U8(ctx.r11.u32 + 0);
	// addi r4,r11,6
	ctx.r4.s64 = ctx.r11.s64 + 6;
	// lbz r9,1(r11)
	ctx.r9.u64 = REX_LOAD_U8(ctx.r11.u32 + 1);
	// rldicr r8,r8,8,63
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r8.u64, 8) & 0xFFFFFFFFFFFFFFFF;
	// lbz r5,2(r11)
	ctx.r5.u64 = REX_LOAD_U8(ctx.r11.u32 + 2);
	// lbz r6,3(r11)
	ctx.r6.u64 = REX_LOAD_U8(ctx.r11.u32 + 3);
	// add r9,r9,r8
	ctx.r9.u64 = ctx.r9.u64 + ctx.r8.u64;
	// lbz r8,5(r11)
	ctx.r8.u64 = REX_LOAD_U8(ctx.r11.u32 + 5);
	// lbz r7,4(r11)
	ctx.r7.u64 = REX_LOAD_U8(ctx.r11.u32 + 4);
	// rldicr r11,r9,8,55
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r9.u64, 8) & 0xFFFFFFFFFFFFFF00;
	// lwz r10,8(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 8);
	// ld r9,0(r31)
	ctx.r9.u64 = REX_LOAD_U64(ctx.r31.u32 + 0);
	// add r11,r11,r5
	ctx.r11.u64 = ctx.r11.u64 + ctx.r5.u64;
	// stw r4,12(r31)
	REX_STORE_U32(ctx.r31.u32 + 12, ctx.r4.u32);
	// rldicr r11,r11,8,55
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u64, 8) & 0xFFFFFFFFFFFFFF00;
	// add r11,r11,r6
	ctx.r11.u64 = ctx.r11.u64 + ctx.r6.u64;
	// rldicr r11,r11,8,55
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u64, 8) & 0xFFFFFFFFFFFFFF00;
	// add r11,r11,r7
	ctx.r11.u64 = ctx.r11.u64 + ctx.r7.u64;
	// rldicr r11,r11,8,55
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u64, 8) & 0xFFFFFFFFFFFFFF00;
	// add r11,r11,r8
	ctx.r11.u64 = ctx.r11.u64 + ctx.r8.u64;
	// neg r8,r10
	ctx.r8.s64 = static_cast<int64_t>(-ctx.r10.u64);
	// addi r10,r10,48
	ctx.r10.s64 = ctx.r10.s64 + 48;
	// extsw r8,r8
	ctx.r8.s64 = ctx.r8.s32;
	// stw r10,8(r31)
	REX_STORE_U32(ctx.r31.u32 + 8, ctx.r10.u32);
	// sld r11,r11,r8
	ctx.r11.u64 = ctx.r8.u8 & 0x40 ? 0 : (ctx.r11.u64 << (ctx.r8.u8 & 0x7F));
	// add r11,r11,r9
	ctx.r11.u64 = ctx.r11.u64 + ctx.r9.u64;
	// std r11,0(r31)
	REX_STORE_U64(ctx.r31.u32 + 0, ctx.r11.u64);
loc_8290E500:
	// srawi r30,r30,4
	ctx.xer.ca = (ctx.r30.s32 < 0) & ((ctx.r30.u32 & 0xF) != 0);
	ctx.r30.s64 = ctx.r30.s32 >> 4;
	// b 0x8290e548
	goto loc_8290E548;
loc_8290E508:
	// li r4,8
	ctx.r4.s64 = 8;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x824c45b8
	ctx.lr = 0x8290E514;
	sub_824C45B8(ctx, base);
loc_8290E514:
	// ld r11,0(r31)
	ctx.r11.u64 = REX_LOAD_U64(ctx.r31.u32 + 0);
	// li r4,1
	ctx.r4.s64 = 1;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// rldicl r11,r11,1,63
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u64, 1) & 0x1;
	// rotlwi r29,r11,0
	ctx.r29.u64 = __builtin_rotateleft32(ctx.r11.u32, 0);
	// bl 0x824c45b8
	ctx.lr = 0x8290E52C;
	sub_824C45B8(ctx, base);
	// add r11,r30,r29
	ctx.r11.u64 = ctx.r30.u64 + ctx.r29.u64;
	// add r11,r11,r15
	ctx.r11.u64 = ctx.r11.u64 + ctx.r15.u64;
	// rlwinm r11,r11,1,0,30
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 1) & 0xFFFFFFFE;
	// lhzx r11,r11,r28
	ctx.r11.u64 = REX_LOAD_U16(ctx.r11.u32 + ctx.r28.u32);
	// extsh r30,r11
	ctx.r30.s64 = ctx.r11.s16;
	// cmpwi cr6,r30,0
	ctx.cr6.compare<int32_t>(ctx.r30.s32, 0, ctx.xer);
	// blt cr6,0x8290e514
	if (ctx.cr6.lt) goto loc_8290E514;
loc_8290E548:
	// lwz r31,0(r18)
	ctx.r31.u64 = REX_LOAD_U32(ctx.r18.u32 + 0);
	// mr r19,r30
	ctx.r19.u64 = ctx.r30.u64;
	// lwz r11,20(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 20);
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq cr6,0x8290e574
	if (ctx.cr6.eq) goto loc_8290E574;
	// li r11,4
	ctx.r11.s64 = 4;
	// li r12,1
	ctx.r12.s64 = 1;
	// clrldi r11,r11,32
	ctx.r11.u64 = ctx.r11.u64 & 0xFFFFFFFF;
	// rldicr r12,r12,63,63
	ctx.r12.u64 = __builtin_rotateleft64(ctx.r12.u64, 63) & 0xFFFFFFFFFFFFFFFF;
	// or r11,r11,r12
	ctx.r11.u64 = ctx.r11.u64 | ctx.r12.u64;
	// b 0x8290ea8c
	goto loc_8290EA8C;
loc_8290E574:
	// lbz r11,19(r18)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r18.u32 + 19);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x8290e84c
	if (ctx.cr6.eq) goto loc_8290E84C;
	// lbz r11,1065(r18)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r18.u32 + 1065);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x8290e5c4
	if (ctx.cr6.eq) goto loc_8290E5C4;
	// lwz r10,0(r17)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r17.u32 + 0);
	// rlwinm r10,r10,20,12,31
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 20) & 0xFFFFF;
	// and r11,r10,r11
	ctx.r11.u64 = ctx.r10.u64 & ctx.r11.u64;
	// clrlwi r11,r11,28
	ctx.r11.u64 = ctx.r11.u32 & 0xF;
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x8290e5b0
	if (ctx.cr6.eq) goto loc_8290E5B0;
	// lbz r11,1066(r18)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r18.u32 + 1066);
	// rotlwi r11,r11,1
	ctx.r11.u64 = __builtin_rotateleft32(ctx.r11.u32, 1);
	// b 0x8290e818
	goto loc_8290E818;
loc_8290E5B0:
	// lbz r11,1064(r18)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r18.u32 + 1064);
	// lbz r10,1069(r18)
	ctx.r10.u64 = REX_LOAD_U8(ctx.r18.u32 + 1069);
	// rotlwi r11,r11,1
	ctx.r11.u64 = __builtin_rotateleft32(ctx.r11.u32, 1);
	// add r11,r11,r10
	ctx.r11.u64 = ctx.r11.u64 + ctx.r10.u64;
	// b 0x8290e818
	goto loc_8290E818;
loc_8290E5C4:
	// lbz r11,1070(r18)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r18.u32 + 1070);
	// mr r29,r14
	ctx.r29.u64 = ctx.r14.u64;
	// lwz r9,8(r31)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r31.u32 + 8);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// addi r11,r9,16
	ctx.r11.s64 = ctx.r9.s64 + 16;
	// beq cr6,0x8290e6ac
	if (ctx.cr6.eq) goto loc_8290E6AC;
	// li r30,1
	ctx.r30.s64 = 1;
	// cmplwi cr6,r11,1
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 1, ctx.xer);
	// bge cr6,0x8290e640
	if (!ctx.cr6.lt) goto loc_8290E640;
loc_8290E5E8:
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x8290e640
	if (ctx.cr6.eq) goto loc_8290E640;
	// subfic r8,r11,64
	ctx.xer.ca = ctx.r11.u32 <= 64;
	ctx.r8.u64 = static_cast<uint64_t>(64) - ctx.r11.u64;
	// ld r10,0(r31)
	ctx.r10.u64 = REX_LOAD_U64(ctx.r31.u32 + 0);
	// subf. r9,r11,r9
	ctx.r9.u64 = ctx.r9.u64 - ctx.r11.u64;
	ctx.cr0.compare<int32_t>(ctx.r9.s32, 0, ctx.xer);
	// clrldi r8,r8,32
	ctx.r8.u64 = ctx.r8.u64 & 0xFFFFFFFF;
	// subf r30,r11,r30
	ctx.r30.u64 = ctx.r30.u64 - ctx.r11.u64;
	// clrldi r11,r11,32
	ctx.r11.u64 = ctx.r11.u64 & 0xFFFFFFFF;
	// stw r9,8(r31)
	REX_STORE_U32(ctx.r31.u32 + 8, ctx.r9.u32);
	// srd r8,r10,r8
	ctx.r8.u64 = ctx.r8.u8 & 0x40 ? 0 : (ctx.r10.u64 >> (ctx.r8.u8 & 0x7F));
	// sld r11,r10,r11
	ctx.r11.u64 = ctx.r11.u8 & 0x40 ? 0 : (ctx.r10.u64 << (ctx.r11.u8 & 0x7F));
	// rotlwi r10,r8,0
	ctx.r10.u64 = __builtin_rotateleft32(ctx.r8.u32, 0);
	// std r11,0(r31)
	REX_STORE_U64(ctx.r31.u32 + 0, ctx.r11.u64);
	// slw r11,r10,r30
	ctx.r11.u64 = ctx.r30.u8 & 0x20 ? 0 : (ctx.r10.u32 << (ctx.r30.u8 & 0x3F));
	// add r29,r11,r29
	ctx.r29.u64 = ctx.r11.u64 + ctx.r29.u64;
	// bge 0x8290e630
	if (!ctx.cr0.lt) goto loc_8290E630;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x824c44e8
	ctx.lr = 0x8290E630;
	sub_824C44E8(ctx, base);
loc_8290E630:
	// lwz r9,8(r31)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r31.u32 + 8);
	// addi r11,r9,16
	ctx.r11.s64 = ctx.r9.s64 + 16;
	// cmplw cr6,r30,r11
	ctx.cr6.compare<uint32_t>(ctx.r30.u32, ctx.r11.u32, ctx.xer);
	// bgt cr6,0x8290e5e8
	if (ctx.cr6.gt) goto loc_8290E5E8;
loc_8290E640:
	// subfic r9,r30,64
	ctx.xer.ca = ctx.r30.u32 <= 64;
	ctx.r9.u64 = static_cast<uint64_t>(64) - ctx.r30.u64;
	// ld r11,0(r31)
	ctx.r11.u64 = REX_LOAD_U64(ctx.r31.u32 + 0);
	// clrldi r8,r30,32
	ctx.r8.u64 = ctx.r30.u64 & 0xFFFFFFFF;
	// lwz r10,8(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 8);
	// clrldi r9,r9,32
	ctx.r9.u64 = ctx.r9.u64 & 0xFFFFFFFF;
	// subf. r10,r30,r10
	ctx.r10.u64 = ctx.r10.u64 - ctx.r30.u64;
	ctx.cr0.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// stw r10,8(r31)
	REX_STORE_U32(ctx.r31.u32 + 8, ctx.r10.u32);
	// sld r8,r11,r8
	ctx.r8.u64 = ctx.r8.u8 & 0x40 ? 0 : (ctx.r11.u64 << (ctx.r8.u8 & 0x7F));
	// srd r9,r11,r9
	ctx.r9.u64 = ctx.r9.u8 & 0x40 ? 0 : (ctx.r11.u64 >> (ctx.r9.u8 & 0x7F));
	// rotlwi r11,r9,0
	ctx.r11.u64 = __builtin_rotateleft32(ctx.r9.u32, 0);
	// add r30,r11,r29
	ctx.r30.u64 = ctx.r11.u64 + ctx.r29.u64;
	// std r8,0(r31)
	REX_STORE_U64(ctx.r31.u32 + 0, ctx.r8.u64);
	// bge 0x8290e67c
	if (!ctx.cr0.lt) goto loc_8290E67C;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x824c44e8
	ctx.lr = 0x8290E67C;
	sub_824C44E8(ctx, base);
loc_8290E67C:
	// cmplwi cr6,r30,0
	ctx.cr6.compare<uint32_t>(ctx.r30.u32, 0, ctx.xer);
	// beq cr6,0x8290e694
	if (ctx.cr6.eq) goto loc_8290E694;
	// lbz r11,1066(r18)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r18.u32 + 1066);
	// rotlwi r11,r11,1
	ctx.r11.u64 = __builtin_rotateleft32(ctx.r11.u32, 1);
	// addi r11,r11,-1
	ctx.r11.s64 = ctx.r11.s64 + -1;
	// b 0x8290e81c
	goto loc_8290E81C;
loc_8290E694:
	// lbz r11,1064(r18)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r18.u32 + 1064);
	// lbz r10,1069(r18)
	ctx.r10.u64 = REX_LOAD_U8(ctx.r18.u32 + 1069);
	// rotlwi r11,r11,1
	ctx.r11.u64 = __builtin_rotateleft32(ctx.r11.u32, 1);
	// add r11,r11,r10
	ctx.r11.u64 = ctx.r11.u64 + ctx.r10.u64;
	// addi r11,r11,-1
	ctx.r11.s64 = ctx.r11.s64 + -1;
	// b 0x8290e81c
	goto loc_8290E81C;
loc_8290E6AC:
	// li r30,3
	ctx.r30.s64 = 3;
	// cmplwi cr6,r11,3
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 3, ctx.xer);
	// bge cr6,0x8290e710
	if (!ctx.cr6.lt) goto loc_8290E710;
loc_8290E6B8:
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x8290e710
	if (ctx.cr6.eq) goto loc_8290E710;
	// subfic r8,r11,64
	ctx.xer.ca = ctx.r11.u32 <= 64;
	ctx.r8.u64 = static_cast<uint64_t>(64) - ctx.r11.u64;
	// ld r10,0(r31)
	ctx.r10.u64 = REX_LOAD_U64(ctx.r31.u32 + 0);
	// subf. r9,r11,r9
	ctx.r9.u64 = ctx.r9.u64 - ctx.r11.u64;
	ctx.cr0.compare<int32_t>(ctx.r9.s32, 0, ctx.xer);
	// clrldi r8,r8,32
	ctx.r8.u64 = ctx.r8.u64 & 0xFFFFFFFF;
	// subf r30,r11,r30
	ctx.r30.u64 = ctx.r30.u64 - ctx.r11.u64;
	// clrldi r11,r11,32
	ctx.r11.u64 = ctx.r11.u64 & 0xFFFFFFFF;
	// stw r9,8(r31)
	REX_STORE_U32(ctx.r31.u32 + 8, ctx.r9.u32);
	// srd r8,r10,r8
	ctx.r8.u64 = ctx.r8.u8 & 0x40 ? 0 : (ctx.r10.u64 >> (ctx.r8.u8 & 0x7F));
	// sld r11,r10,r11
	ctx.r11.u64 = ctx.r11.u8 & 0x40 ? 0 : (ctx.r10.u64 << (ctx.r11.u8 & 0x7F));
	// rotlwi r10,r8,0
	ctx.r10.u64 = __builtin_rotateleft32(ctx.r8.u32, 0);
	// std r11,0(r31)
	REX_STORE_U64(ctx.r31.u32 + 0, ctx.r11.u64);
	// slw r11,r10,r30
	ctx.r11.u64 = ctx.r30.u8 & 0x20 ? 0 : (ctx.r10.u32 << (ctx.r30.u8 & 0x3F));
	// add r29,r11,r29
	ctx.r29.u64 = ctx.r11.u64 + ctx.r29.u64;
	// bge 0x8290e700
	if (!ctx.cr0.lt) goto loc_8290E700;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x824c44e8
	ctx.lr = 0x8290E700;
	sub_824C44E8(ctx, base);
loc_8290E700:
	// lwz r9,8(r31)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r31.u32 + 8);
	// addi r11,r9,16
	ctx.r11.s64 = ctx.r9.s64 + 16;
	// cmplw cr6,r30,r11
	ctx.cr6.compare<uint32_t>(ctx.r30.u32, ctx.r11.u32, ctx.xer);
	// bgt cr6,0x8290e6b8
	if (ctx.cr6.gt) goto loc_8290E6B8;
loc_8290E710:
	// subfic r9,r30,64
	ctx.xer.ca = ctx.r30.u32 <= 64;
	ctx.r9.u64 = static_cast<uint64_t>(64) - ctx.r30.u64;
	// ld r11,0(r31)
	ctx.r11.u64 = REX_LOAD_U64(ctx.r31.u32 + 0);
	// clrldi r8,r30,32
	ctx.r8.u64 = ctx.r30.u64 & 0xFFFFFFFF;
	// lwz r10,8(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 8);
	// clrldi r9,r9,32
	ctx.r9.u64 = ctx.r9.u64 & 0xFFFFFFFF;
	// subf. r10,r30,r10
	ctx.r10.u64 = ctx.r10.u64 - ctx.r30.u64;
	ctx.cr0.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// stw r10,8(r31)
	REX_STORE_U32(ctx.r31.u32 + 8, ctx.r10.u32);
	// sld r8,r11,r8
	ctx.r8.u64 = ctx.r8.u8 & 0x40 ? 0 : (ctx.r11.u64 << (ctx.r8.u8 & 0x7F));
	// srd r9,r11,r9
	ctx.r9.u64 = ctx.r9.u8 & 0x40 ? 0 : (ctx.r11.u64 >> (ctx.r9.u8 & 0x7F));
	// rotlwi r11,r9,0
	ctx.r11.u64 = __builtin_rotateleft32(ctx.r9.u32, 0);
	// add r30,r11,r29
	ctx.r30.u64 = ctx.r11.u64 + ctx.r29.u64;
	// std r8,0(r31)
	REX_STORE_U64(ctx.r31.u32 + 0, ctx.r8.u64);
	// bge 0x8290e74c
	if (!ctx.cr0.lt) goto loc_8290E74C;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x824c44e8
	ctx.lr = 0x8290E74C;
	sub_824C44E8(ctx, base);
loc_8290E74C:
	// cmpwi cr6,r30,7
	ctx.cr6.compare<int32_t>(ctx.r30.s32, 7, ctx.xer);
	// bne cr6,0x8290e80c
	if (!ctx.cr6.eq) goto loc_8290E80C;
	// lwz r31,0(r18)
	ctx.r31.u64 = REX_LOAD_U32(ctx.r18.u32 + 0);
	// li r30,5
	ctx.r30.s64 = 5;
	// mr r29,r14
	ctx.r29.u64 = ctx.r14.u64;
	// lwz r9,8(r31)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r31.u32 + 8);
	// addi r11,r9,16
	ctx.r11.s64 = ctx.r9.s64 + 16;
	// cmplwi cr6,r11,5
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 5, ctx.xer);
	// bge cr6,0x8290e7c8
	if (!ctx.cr6.lt) goto loc_8290E7C8;
loc_8290E770:
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x8290e7c8
	if (ctx.cr6.eq) goto loc_8290E7C8;
	// subfic r8,r11,64
	ctx.xer.ca = ctx.r11.u32 <= 64;
	ctx.r8.u64 = static_cast<uint64_t>(64) - ctx.r11.u64;
	// ld r10,0(r31)
	ctx.r10.u64 = REX_LOAD_U64(ctx.r31.u32 + 0);
	// subf. r9,r11,r9
	ctx.r9.u64 = ctx.r9.u64 - ctx.r11.u64;
	ctx.cr0.compare<int32_t>(ctx.r9.s32, 0, ctx.xer);
	// clrldi r8,r8,32
	ctx.r8.u64 = ctx.r8.u64 & 0xFFFFFFFF;
	// subf r30,r11,r30
	ctx.r30.u64 = ctx.r30.u64 - ctx.r11.u64;
	// clrldi r11,r11,32
	ctx.r11.u64 = ctx.r11.u64 & 0xFFFFFFFF;
	// stw r9,8(r31)
	REX_STORE_U32(ctx.r31.u32 + 8, ctx.r9.u32);
	// srd r8,r10,r8
	ctx.r8.u64 = ctx.r8.u8 & 0x40 ? 0 : (ctx.r10.u64 >> (ctx.r8.u8 & 0x7F));
	// sld r11,r10,r11
	ctx.r11.u64 = ctx.r11.u8 & 0x40 ? 0 : (ctx.r10.u64 << (ctx.r11.u8 & 0x7F));
	// rotlwi r10,r8,0
	ctx.r10.u64 = __builtin_rotateleft32(ctx.r8.u32, 0);
	// std r11,0(r31)
	REX_STORE_U64(ctx.r31.u32 + 0, ctx.r11.u64);
	// slw r11,r10,r30
	ctx.r11.u64 = ctx.r30.u8 & 0x20 ? 0 : (ctx.r10.u32 << (ctx.r30.u8 & 0x3F));
	// add r29,r11,r29
	ctx.r29.u64 = ctx.r11.u64 + ctx.r29.u64;
	// bge 0x8290e7b8
	if (!ctx.cr0.lt) goto loc_8290E7B8;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x824c44e8
	ctx.lr = 0x8290E7B8;
	sub_824C44E8(ctx, base);
loc_8290E7B8:
	// lwz r9,8(r31)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r31.u32 + 8);
	// addi r11,r9,16
	ctx.r11.s64 = ctx.r9.s64 + 16;
	// cmplw cr6,r30,r11
	ctx.cr6.compare<uint32_t>(ctx.r30.u32, ctx.r11.u32, ctx.xer);
	// bgt cr6,0x8290e770
	if (ctx.cr6.gt) goto loc_8290E770;
loc_8290E7C8:
	// subfic r9,r30,64
	ctx.xer.ca = ctx.r30.u32 <= 64;
	ctx.r9.u64 = static_cast<uint64_t>(64) - ctx.r30.u64;
	// ld r11,0(r31)
	ctx.r11.u64 = REX_LOAD_U64(ctx.r31.u32 + 0);
	// clrldi r8,r30,32
	ctx.r8.u64 = ctx.r30.u64 & 0xFFFFFFFF;
	// lwz r10,8(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 8);
	// clrldi r9,r9,32
	ctx.r9.u64 = ctx.r9.u64 & 0xFFFFFFFF;
	// subf. r10,r30,r10
	ctx.r10.u64 = ctx.r10.u64 - ctx.r30.u64;
	ctx.cr0.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// stw r10,8(r31)
	REX_STORE_U32(ctx.r31.u32 + 8, ctx.r10.u32);
	// sld r8,r11,r8
	ctx.r8.u64 = ctx.r8.u8 & 0x40 ? 0 : (ctx.r11.u64 << (ctx.r8.u8 & 0x7F));
	// srd r9,r11,r9
	ctx.r9.u64 = ctx.r9.u8 & 0x40 ? 0 : (ctx.r11.u64 >> (ctx.r9.u8 & 0x7F));
	// rotlwi r11,r9,0
	ctx.r11.u64 = __builtin_rotateleft32(ctx.r9.u32, 0);
	// add r30,r11,r29
	ctx.r30.u64 = ctx.r11.u64 + ctx.r29.u64;
	// std r8,0(r31)
	REX_STORE_U64(ctx.r31.u32 + 0, ctx.r8.u64);
	// bge 0x8290e804
	if (!ctx.cr0.lt) goto loc_8290E804;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x824c44e8
	ctx.lr = 0x8290E804;
	sub_824C44E8(ctx, base);
loc_8290E804:
	// mr r11,r30
	ctx.r11.u64 = ctx.r30.u64;
	// b 0x8290e814
	goto loc_8290E814;
loc_8290E80C:
	// lbz r11,1064(r18)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r18.u32 + 1064);
	// add r11,r11,r30
	ctx.r11.u64 = ctx.r11.u64 + ctx.r30.u64;
loc_8290E814:
	// rlwinm r11,r11,1,0,30
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 1) & 0xFFFFFFFE;
loc_8290E818:
	// addi r11,r11,255
	ctx.r11.s64 = ctx.r11.s64 + 255;
loc_8290E81C:
	// stb r11,4(r17)
	REX_STORE_U8(ctx.r17.u32 + 4, ctx.r11.u8);
	// clrlwi r11,r11,24
	ctx.r11.u64 = ctx.r11.u32 & 0xFF;
	// cmplwi cr6,r11,1
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 1, ctx.xer);
	// blt cr6,0x8290e834
	if (ctx.cr6.lt) goto loc_8290E834;
	// cmplwi cr6,r11,62
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 62, ctx.xer);
	// ble cr6,0x8290e84c
	if (!ctx.cr6.gt) goto loc_8290E84C;
loc_8290E834:
	// li r11,1
	ctx.r11.s64 = 1;
	// li r12,1
	ctx.r12.s64 = 1;
	// clrldi r11,r11,32
	ctx.r11.u64 = ctx.r11.u64 & 0xFFFFFFFF;
	// rldicr r12,r12,63,63
	ctx.r12.u64 = __builtin_rotateleft64(ctx.r12.u64, 63) & 0xFFFFFFFFFFFFFFFF;
	// or r11,r11,r12
	ctx.r11.u64 = ctx.r11.u64 | ctx.r12.u64;
	// b 0x8290ea8c
	goto loc_8290EA8C;
loc_8290E84C:
	// lwz r11,0(r17)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r17.u32 + 0);
	// cmpwi cr6,r27,0
	ctx.cr6.compare<int32_t>(ctx.r27.s32, 0, ctx.xer);
	// rlwinm r11,r11,0,2,0
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 0) & 0xFFFFFFFFBFFFFFFF;
	// stw r11,0(r17)
	REX_STORE_U32(ctx.r17.u32 + 0, ctx.r11.u32);
	// beq cr6,0x8290e8d4
	if (ctx.cr6.eq) goto loc_8290E8D4;
	// lwz r3,0(r18)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r18.u32 + 0);
	// ld r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U64(ctx.r3.u32 + 0);
	// lwz r10,8(r3)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r3.u32 + 8);
	// rldicr r9,r11,1,62
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r11.u64, 1) & 0xFFFFFFFFFFFFFFFE;
	// rldicl r8,r11,1,63
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r11.u64, 1) & 0x1;
	// addic. r11,r10,-1
	ctx.xer.ca = ctx.r10.u32 > 0;
	ctx.r11.s64 = ctx.r10.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// rotlwi r30,r8,0
	ctx.r30.u64 = __builtin_rotateleft32(ctx.r8.u32, 0);
	// std r9,0(r3)
	REX_STORE_U64(ctx.r3.u32 + 0, ctx.r9.u64);
	// stw r11,8(r3)
	REX_STORE_U32(ctx.r3.u32 + 8, ctx.r11.u32);
	// bge 0x8290e88c
	if (!ctx.cr0.lt) goto loc_8290E88C;
	// bl 0x824c44e8
	ctx.lr = 0x8290E88C;
	sub_824C44E8(ctx, base);
loc_8290E88C:
	// mr r11,r30
	ctx.r11.u64 = ctx.r30.u64;
	// cmpwi cr6,r30,0
	ctx.cr6.compare<int32_t>(ctx.r30.s32, 0, ctx.xer);
	// beq cr6,0x8290e8c8
	if (ctx.cr6.eq) goto loc_8290E8C8;
	// lwz r3,0(r18)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r18.u32 + 0);
	// ld r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U64(ctx.r3.u32 + 0);
	// lwz r10,8(r3)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r3.u32 + 8);
	// rldicr r9,r11,1,62
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r11.u64, 1) & 0xFFFFFFFFFFFFFFFE;
	// rldicl r8,r11,1,63
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r11.u64, 1) & 0x1;
	// addic. r11,r10,-1
	ctx.xer.ca = ctx.r10.u32 > 0;
	ctx.r11.s64 = ctx.r10.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// rotlwi r31,r8,0
	ctx.r31.u64 = __builtin_rotateleft32(ctx.r8.u32, 0);
	// std r9,0(r3)
	REX_STORE_U64(ctx.r3.u32 + 0, ctx.r9.u64);
	// stw r11,8(r3)
	REX_STORE_U32(ctx.r3.u32 + 8, ctx.r11.u32);
	// bge 0x8290e8c4
	if (!ctx.cr0.lt) goto loc_8290E8C4;
	// bl 0x824c44e8
	ctx.lr = 0x8290E8C4;
	sub_824C44E8(ctx, base);
loc_8290E8C4:
	// add r11,r31,r30
	ctx.r11.u64 = ctx.r31.u64 + ctx.r30.u64;
loc_8290E8C8:
	// lwz r10,0(r17)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r17.u32 + 0);
	// rlwimi r10,r11,22,8,9
	ctx.r10.u64 = (__builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 22) & 0xC00000) | (ctx.r10.u64 & 0xFFFFFFFFFF3FFFFF);
	// stw r10,0(r17)
	REX_STORE_U32(ctx.r17.u32 + 0, ctx.r10.u32);
loc_8290E8D4:
	// cmpwi cr6,r26,0
	ctx.cr6.compare<int32_t>(ctx.r26.s32, 0, ctx.xer);
	// beq cr6,0x8290ea68
	if (ctx.cr6.eq) goto loc_8290EA68;
	// lwz r31,0(r18)
	ctx.r31.u64 = REX_LOAD_U32(ctx.r18.u32 + 0);
	// lwz r11,124(r18)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r18.u32 + 124);
	// ld r9,0(r31)
	ctx.r9.u64 = REX_LOAD_U64(ctx.r31.u32 + 0);
	// lwz r28,0(r11)
	ctx.r28.u64 = REX_LOAD_U32(ctx.r11.u32 + 0);
	// rldicl r11,r9,8,56
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r9.u64, 8) & 0xFF;
	// rlwinm r11,r11,1,0,30
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 1) & 0xFFFFFFFE;
	// lhzx r11,r11,r28
	ctx.r11.u64 = REX_LOAD_U16(ctx.r11.u32 + ctx.r28.u32);
	// extsh r30,r11
	ctx.r30.s64 = ctx.r11.s16;
	// cmpwi cr6,r30,0
	ctx.cr6.compare<int32_t>(ctx.r30.s32, 0, ctx.xer);
	// blt cr6,0x8290e9c4
	if (ctx.cr6.lt) goto loc_8290E9C4;
	// clrlwi r11,r30,28
	ctx.r11.u64 = ctx.r30.u32 & 0xF;
	// lwz r10,8(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 8);
	// cmpw cr6,r10,r11
	ctx.cr6.compare<int32_t>(ctx.r10.s32, ctx.r11.s32, ctx.xer);
	// sld r9,r9,r11
	ctx.r9.u64 = ctx.r11.u8 & 0x40 ? 0 : (ctx.r9.u64 << (ctx.r11.u8 & 0x7F));
	// std r9,0(r31)
	REX_STORE_U64(ctx.r31.u32 + 0, ctx.r9.u64);
	// subf r9,r11,r10
	ctx.r9.u64 = ctx.r10.u64 - ctx.r11.u64;
	// stw r9,8(r31)
	REX_STORE_U32(ctx.r31.u32 + 8, ctx.r9.u32);
	// bge cr6,0x8290e9bc
	if (!ctx.cr6.lt) goto loc_8290E9BC;
loc_8290E924:
	// lwz r10,16(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 16);
	// lwz r11,12(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 12);
	// addi r10,r10,-4
	ctx.r10.s64 = ctx.r10.s64 + -4;
	// cmplw cr6,r11,r10
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, ctx.r10.u32, ctx.xer);
	// blt cr6,0x8290e950
	if (ctx.cr6.lt) goto loc_8290E950;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x824c4428
	ctx.lr = 0x8290E940;
	sub_824C4428(ctx, base);
	// cmplwi cr6,r3,1
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 1, ctx.xer);
	// beq cr6,0x8290e924
	if (ctx.cr6.eq) goto loc_8290E924;
	// srawi r30,r30,4
	ctx.xer.ca = (ctx.r30.s32 < 0) & ((ctx.r30.u32 & 0xF) != 0);
	ctx.r30.s64 = ctx.r30.s32 >> 4;
	// b 0x8290ea04
	goto loc_8290EA04;
loc_8290E950:
	// lbz r8,0(r11)
	ctx.r8.u64 = REX_LOAD_U8(ctx.r11.u32 + 0);
	// addi r4,r11,6
	ctx.r4.s64 = ctx.r11.s64 + 6;
	// lbz r9,1(r11)
	ctx.r9.u64 = REX_LOAD_U8(ctx.r11.u32 + 1);
	// rldicr r8,r8,8,63
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r8.u64, 8) & 0xFFFFFFFFFFFFFFFF;
	// lbz r5,2(r11)
	ctx.r5.u64 = REX_LOAD_U8(ctx.r11.u32 + 2);
	// lbz r6,3(r11)
	ctx.r6.u64 = REX_LOAD_U8(ctx.r11.u32 + 3);
	// add r9,r9,r8
	ctx.r9.u64 = ctx.r9.u64 + ctx.r8.u64;
	// lbz r8,5(r11)
	ctx.r8.u64 = REX_LOAD_U8(ctx.r11.u32 + 5);
	// lbz r7,4(r11)
	ctx.r7.u64 = REX_LOAD_U8(ctx.r11.u32 + 4);
	// rldicr r11,r9,8,55
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r9.u64, 8) & 0xFFFFFFFFFFFFFF00;
	// lwz r10,8(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 8);
	// ld r9,0(r31)
	ctx.r9.u64 = REX_LOAD_U64(ctx.r31.u32 + 0);
	// add r11,r11,r5
	ctx.r11.u64 = ctx.r11.u64 + ctx.r5.u64;
	// stw r4,12(r31)
	REX_STORE_U32(ctx.r31.u32 + 12, ctx.r4.u32);
	// rldicr r11,r11,8,55
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u64, 8) & 0xFFFFFFFFFFFFFF00;
	// add r11,r11,r6
	ctx.r11.u64 = ctx.r11.u64 + ctx.r6.u64;
	// rldicr r11,r11,8,55
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u64, 8) & 0xFFFFFFFFFFFFFF00;
	// add r11,r11,r7
	ctx.r11.u64 = ctx.r11.u64 + ctx.r7.u64;
	// rldicr r11,r11,8,55
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u64, 8) & 0xFFFFFFFFFFFFFF00;
	// add r11,r11,r8
	ctx.r11.u64 = ctx.r11.u64 + ctx.r8.u64;
	// neg r8,r10
	ctx.r8.s64 = static_cast<int64_t>(-ctx.r10.u64);
	// addi r10,r10,48
	ctx.r10.s64 = ctx.r10.s64 + 48;
	// extsw r8,r8
	ctx.r8.s64 = ctx.r8.s32;
	// stw r10,8(r31)
	REX_STORE_U32(ctx.r31.u32 + 8, ctx.r10.u32);
	// sld r11,r11,r8
	ctx.r11.u64 = ctx.r8.u8 & 0x40 ? 0 : (ctx.r11.u64 << (ctx.r8.u8 & 0x7F));
	// add r11,r11,r9
	ctx.r11.u64 = ctx.r11.u64 + ctx.r9.u64;
	// std r11,0(r31)
	REX_STORE_U64(ctx.r31.u32 + 0, ctx.r11.u64);
loc_8290E9BC:
	// srawi r30,r30,4
	ctx.xer.ca = (ctx.r30.s32 < 0) & ((ctx.r30.u32 & 0xF) != 0);
	ctx.r30.s64 = ctx.r30.s32 >> 4;
	// b 0x8290ea04
	goto loc_8290EA04;
loc_8290E9C4:
	// li r4,8
	ctx.r4.s64 = 8;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x824c45b8
	ctx.lr = 0x8290E9D0;
	sub_824C45B8(ctx, base);
loc_8290E9D0:
	// ld r11,0(r31)
	ctx.r11.u64 = REX_LOAD_U64(ctx.r31.u32 + 0);
	// li r4,1
	ctx.r4.s64 = 1;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// rldicl r11,r11,1,63
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u64, 1) & 0x1;
	// rotlwi r29,r11,0
	ctx.r29.u64 = __builtin_rotateleft32(ctx.r11.u32, 0);
	// bl 0x824c45b8
	ctx.lr = 0x8290E9E8;
	sub_824C45B8(ctx, base);
	// add r11,r30,r29
	ctx.r11.u64 = ctx.r30.u64 + ctx.r29.u64;
	// add r11,r11,r15
	ctx.r11.u64 = ctx.r11.u64 + ctx.r15.u64;
	// rlwinm r11,r11,1,0,30
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 1) & 0xFFFFFFFE;
	// lhzx r11,r11,r28
	ctx.r11.u64 = REX_LOAD_U16(ctx.r11.u32 + ctx.r28.u32);
	// extsh r30,r11
	ctx.r30.s64 = ctx.r11.s16;
	// cmpwi cr6,r30,0
	ctx.cr6.compare<int32_t>(ctx.r30.s32, 0, ctx.xer);
	// blt cr6,0x8290e9d0
	if (ctx.cr6.lt) goto loc_8290E9D0;
loc_8290EA04:
	// lwz r11,0(r18)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r18.u32 + 0);
	// lwz r11,20(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 20);
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq cr6,0x8290ea1c
	if (ctx.cr6.eq) goto loc_8290EA1C;
	// li r11,4
	ctx.r11.s64 = 4;
	// b 0x8290ea8c
	goto loc_8290EA8C;
loc_8290EA1C:
	// cmpwi cr6,r30,8
	ctx.cr6.compare<int32_t>(ctx.r30.s32, 8, ctx.xer);
	// li r9,1
	ctx.r9.s64 = 1;
	// blt cr6,0x8290ea2c
	if (ctx.cr6.lt) goto loc_8290EA2C;
	// mr r9,r14
	ctx.r9.u64 = ctx.r14.u64;
loc_8290EA2C:
	// lwz r11,0(r17)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r17.u32 + 0);
	// rlwinm r10,r30,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r30.u32 | (ctx.r30.u64 << 32), 2) & 0xFFFFFFFC;
	// rlwimi r11,r9,28,3,3
	ctx.r11.u64 = (__builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 28) & 0x10000000) | (ctx.r11.u64 & 0xFFFFFFFFEFFFFFFF);
	// lwz r9,124(r1)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r1.u32 + 124);
	// mr r7,r11
	ctx.r7.u64 = ctx.r11.u64;
	// addi r8,r9,64
	ctx.r8.s64 = ctx.r9.s64 + 64;
	// stw r11,0(r17)
	REX_STORE_U32(ctx.r17.u32 + 0, ctx.r11.u32);
	// lwzx r11,r10,r9
	ctx.r11.u64 = REX_LOAD_U32(ctx.r10.u32 + ctx.r9.u32);
	// rlwimi r7,r11,24,5,7
	ctx.r7.u64 = (__builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 24) & 0x7000000) | (ctx.r7.u64 & 0xFFFFFFFFF8FFFFFF);
	// stw r7,0(r17)
	REX_STORE_U32(ctx.r17.u32 + 0, ctx.r7.u32);
	// lwzx r11,r10,r8
	ctx.r11.u64 = REX_LOAD_U32(ctx.r10.u32 + ctx.r8.u32);
	// rotlwi r10,r7,0
	ctx.r10.u64 = __builtin_rotateleft32(ctx.r7.u32, 0);
	// rlwimi r10,r11,20,10,11
	ctx.r10.u64 = (__builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 20) & 0x300000) | (ctx.r10.u64 & 0xFFFFFFFFFFCFFFFF);
	// rlwinm r11,r10,0,5,3
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 0) & 0xFFFFFFFFF7FFFFFF;
loc_8290EA64:
	// stw r11,0(r17)
	REX_STORE_U32(ctx.r17.u32 + 0, ctx.r11.u32);
loc_8290EA68:
	// stb r19,5(r17)
	REX_STORE_U8(ctx.r17.u32 + 5, ctx.r19.u8);
loc_8290EA6C:
	// cmpwi cr6,r22,0
	ctx.cr6.compare<int32_t>(ctx.r22.s32, 0, ctx.xer);
	// beq cr6,0x8290ea80
	if (ctx.cr6.eq) goto loc_8290EA80;
	// li r11,16384
	ctx.r11.s64 = 16384;
	// rldimi r11,r11,32,0
	ctx.r11.u64 = (__builtin_rotateleft64(ctx.r11.u64, 32) & 0xFFFFFFFF00000000) | (ctx.r11.u64 & 0xFFFFFFFF);
	// b 0x8290ea8c
	goto loc_8290EA8C;
loc_8290EA80:
	// clrldi r10,r21,32
	ctx.r10.u64 = ctx.r21.u64 & 0xFFFFFFFF;
	// rldicr r11,r20,32,31
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r20.u64, 32) & 0xFFFFFFFF00000000;
	// or r11,r11,r10
	ctx.r11.u64 = ctx.r11.u64 | ctx.r10.u64;
loc_8290EA8C:
	// li r9,1
	ctx.r9.s64 = 1;
	// rldicr r10,r11,0,1
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r11.u64, 0) & 0xC000000000000000;
	// rldicr r9,r9,63,63
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r9.u64, 63) & 0xFFFFFFFFFFFFFFFF;
	// cmpld cr6,r10,r9
	ctx.cr6.compare<uint64_t>(ctx.r10.u64, ctx.r9.u64, ctx.xer);
	// beq cr6,0x8290f574
	if (ctx.cr6.eq) goto loc_8290F574;
	// lwz r10,80(r1)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r1.u32 + 80);
	// li r6,16384
	ctx.r6.s64 = 16384;
	// lwz r9,1264(r18)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r18.u32 + 1264);
	// sradi r7,r11,32
	ctx.xer.ca = (ctx.r11.s64 < 0) & ((ctx.r11.u64 & 0xFFFFFFFF) != 0);
	ctx.r7.s64 = ctx.r11.s64 >> 32;
	// rlwinm r10,r10,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 2) & 0xFFFFFFFC;
	// rldimi r6,r6,32,0
	ctx.r6.u64 = (__builtin_rotateleft64(ctx.r6.u64, 32) & 0xFFFFFFFF00000000) | (ctx.r6.u64 & 0xFFFFFFFF);
	// cmpld cr6,r11,r6
	ctx.cr6.compare<uint64_t>(ctx.r11.u64, ctx.r6.u64, ctx.xer);
	// stwx r11,r9,r10
	REX_STORE_U32(ctx.r9.u32 + ctx.r10.u32, ctx.r11.u32);
	// lwz r11,1268(r18)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r18.u32 + 1268);
	// stwx r7,r11,r10
	REX_STORE_U32(ctx.r11.u32 + ctx.r10.u32, ctx.r7.u32);
	// bne cr6,0x8290eff0
	if (!ctx.cr6.eq) goto loc_8290EFF0;
	// lbz r9,20(r18)
	ctx.r9.u64 = REX_LOAD_U8(ctx.r18.u32 + 20);
	// lbz r11,4(r17)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r17.u32 + 4);
	// cmplwi cr6,r9,0
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, 0, ctx.xer);
	// lwz r10,152(r18)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r18.u32 + 152);
	// rotlwi r9,r11,2
	ctx.r9.u64 = __builtin_rotateleft32(ctx.r11.u32, 2);
	// lbz r24,5(r17)
	ctx.r24.u64 = REX_LOAD_U8(ctx.r17.u32 + 5);
	// add r11,r11,r9
	ctx.r11.u64 = ctx.r11.u64 + ctx.r9.u64;
	// rlwinm r11,r11,2,0,29
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 2) & 0xFFFFFFFC;
	// add r26,r11,r10
	ctx.r26.u64 = ctx.r11.u64 + ctx.r10.u64;
	// beq cr6,0x8290eb10
	if (ctx.cr6.eq) goto loc_8290EB10;
	// lwz r11,0(r17)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r17.u32 + 0);
	// lwz r9,160(r18)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r18.u32 + 160);
	// lwz r10,164(r18)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r18.u32 + 164);
	// rlwinm r11,r11,12,28,29
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 12) & 0xC;
	// add r23,r9,r11
	ctx.r23.u64 = ctx.r9.u64 + ctx.r11.u64;
	// add r22,r10,r11
	ctx.r22.u64 = ctx.r10.u64 + ctx.r11.u64;
	// b 0x8290eb18
	goto loc_8290EB18;
loc_8290EB10:
	// lwz r23,168(r18)
	ctx.r23.u64 = REX_LOAD_U32(ctx.r18.u32 + 168);
	// lwz r22,172(r18)
	ctx.r22.u64 = REX_LOAD_U32(ctx.r18.u32 + 172);
loc_8290EB18:
	// lhz r11,268(r18)
	ctx.r11.u64 = REX_LOAD_U16(ctx.r18.u32 + 268);
	// rlwinm r10,r24,11,13,20
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r24.u32 | (ctx.r24.u64 << 32), 11) & 0x7F800;
	// lhz r9,270(r18)
	ctx.r9.u64 = REX_LOAD_U16(ctx.r18.u32 + 270);
	// mr r25,r14
	ctx.r25.u64 = ctx.r14.u64;
	// rlwinm r11,r11,0,0,30
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 0) & 0xFFFFFFFE;
	// rlwinm r9,r9,31,1,31
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 31) & 0x7FFFFFFF;
	// or r11,r11,r10
	ctx.r11.u64 = ctx.r11.u64 | ctx.r10.u64;
	// lwz r10,980(r18)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r18.u32 + 980);
	// li r19,119
	ctx.r19.s64 = 119;
	// rlwinm r11,r11,15,0,16
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 15) & 0xFFFF8000;
	// or r11,r11,r9
	ctx.r11.u64 = ctx.r11.u64 | ctx.r9.u64;
	// stw r11,0(r10)
	REX_STORE_U32(ctx.r10.u32 + 0, ctx.r11.u32);
	// lwz r11,980(r18)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r18.u32 + 980);
	// addi r11,r11,4
	ctx.r11.s64 = ctx.r11.s64 + 4;
	// stw r11,980(r18)
	REX_STORE_U32(ctx.r18.u32 + 980, ctx.r11.u32);
	// lis r11,0
	ctx.r11.s64 = 0;
	// ori r20,r11,65533
	ctx.r20.u64 = ctx.r11.u64 | 65533;
	// lis r11,0
	ctx.r11.s64 = 0;
	// ori r21,r11,65535
	ctx.r21.u64 = ctx.r11.u64 | 65535;
loc_8290EB64:
	// clrlwi r10,r24,31
	ctx.r10.u64 = ctx.r24.u32 & 0x1;
	// stw r19,92(r1)
	REX_STORE_U32(ctx.r1.u32 + 92, ctx.r19.u32);
	// rlwinm r11,r25,0,0,29
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r25.u32 | (ctx.r25.u64 << 32), 0) & 0xFFFFFFFC;
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// stw r10,132(r1)
	REX_STORE_U32(ctx.r1.u32 + 132, ctx.r10.u32);
	// bne cr6,0x8290eb88
	if (!ctx.cr6.eq) goto loc_8290EB88;
	// lwz r11,1044(r18)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r18.u32 + 1044);
	// stw r22,100(r1)
	REX_STORE_U32(ctx.r1.u32 + 100, ctx.r22.u32);
	// b 0x8290eb90
	goto loc_8290EB90;
loc_8290EB88:
	// lwz r11,1048(r18)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r18.u32 + 1048);
	// stw r23,100(r1)
	REX_STORE_U32(ctx.r1.u32 + 100, ctx.r23.u32);
loc_8290EB90:
	// stw r11,88(r1)
	REX_STORE_U32(ctx.r1.u32 + 88, ctx.r11.u32);
	// lwz r11,972(r18)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r18.u32 + 972);
	// lwz r10,16(r26)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r26.u32 + 16);
	// addi r11,r11,-128
	ctx.r11.s64 = ctx.r11.s64 + -128;
	// stw r10,96(r1)
	REX_STORE_U32(ctx.r1.u32 + 96, ctx.r10.u32);
	// stw r11,128(r1)
	REX_STORE_U32(ctx.r1.u32 + 128, ctx.r11.u32);
	// stw r11,972(r18)
	REX_STORE_U32(ctx.r18.u32 + 972, ctx.r11.u32);
	// dcbzl r0,r11
	ea = (ctx.r11.u32) & ~127;
	memset((void*)REX_RAW_ADDR(ea), 0, 128);
	// mr r27,r14
	ctx.r27.u64 = ctx.r14.u64;
	// lwz r10,88(r1)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r1.u32 + 88);
	// lwz r31,0(r18)
	ctx.r31.u64 = REX_LOAD_U32(ctx.r18.u32 + 0);
	// lbz r4,8(r10)
	ctx.r4.u64 = REX_LOAD_U8(ctx.r10.u32 + 8);
	// lwz r29,0(r10)
	ctx.r29.u64 = REX_LOAD_U32(ctx.r10.u32 + 0);
	// subfic r10,r4,64
	ctx.xer.ca = ctx.r4.u32 <= 64;
	ctx.r10.u64 = static_cast<uint64_t>(64) - ctx.r4.u64;
	// ld r11,0(r31)
	ctx.r11.u64 = REX_LOAD_U64(ctx.r31.u32 + 0);
	// clrldi r10,r10,32
	ctx.r10.u64 = ctx.r10.u64 & 0xFFFFFFFF;
	// srd r10,r11,r10
	ctx.r10.u64 = ctx.r10.u8 & 0x40 ? 0 : (ctx.r11.u64 >> (ctx.r10.u8 & 0x7F));
	// rlwinm r10,r10,1,0,30
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 1) & 0xFFFFFFFE;
	// lhzx r10,r10,r29
	ctx.r10.u64 = REX_LOAD_U16(ctx.r10.u32 + ctx.r29.u32);
	// extsh r30,r10
	ctx.r30.s64 = ctx.r10.s16;
	// cmpwi cr6,r30,0
	ctx.cr6.compare<int32_t>(ctx.r30.s32, 0, ctx.xer);
	// blt cr6,0x8290eca8
	if (ctx.cr6.lt) goto loc_8290ECA8;
	// clrlwi r10,r30,28
	ctx.r10.u64 = ctx.r30.u32 & 0xF;
	// lwz r9,8(r31)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r31.u32 + 8);
	// cmpw cr6,r9,r10
	ctx.cr6.compare<int32_t>(ctx.r9.s32, ctx.r10.s32, ctx.xer);
	// sld r11,r11,r10
	ctx.r11.u64 = ctx.r10.u8 & 0x40 ? 0 : (ctx.r11.u64 << (ctx.r10.u8 & 0x7F));
	// std r11,0(r31)
	REX_STORE_U64(ctx.r31.u32 + 0, ctx.r11.u64);
	// subf r11,r10,r9
	ctx.r11.u64 = ctx.r9.u64 - ctx.r10.u64;
	// stw r11,8(r31)
	REX_STORE_U32(ctx.r31.u32 + 8, ctx.r11.u32);
	// bge cr6,0x8290eca0
	if (!ctx.cr6.lt) goto loc_8290ECA0;
loc_8290EC08:
	// lwz r10,16(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 16);
	// lwz r11,12(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 12);
	// addi r10,r10,-4
	ctx.r10.s64 = ctx.r10.s64 + -4;
	// cmplw cr6,r11,r10
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, ctx.r10.u32, ctx.xer);
	// blt cr6,0x8290ec34
	if (ctx.cr6.lt) goto loc_8290EC34;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x824c4428
	ctx.lr = 0x8290EC24;
	sub_824C4428(ctx, base);
	// cmplwi cr6,r3,1
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 1, ctx.xer);
	// beq cr6,0x8290ec08
	if (ctx.cr6.eq) goto loc_8290EC08;
	// srawi r30,r30,4
	ctx.xer.ca = (ctx.r30.s32 < 0) & ((ctx.r30.u32 & 0xF) != 0);
	ctx.r30.s64 = ctx.r30.s32 >> 4;
	// b 0x8290ece4
	goto loc_8290ECE4;
loc_8290EC34:
	// lbz r8,0(r11)
	ctx.r8.u64 = REX_LOAD_U8(ctx.r11.u32 + 0);
	// addi r4,r11,6
	ctx.r4.s64 = ctx.r11.s64 + 6;
	// lbz r9,1(r11)
	ctx.r9.u64 = REX_LOAD_U8(ctx.r11.u32 + 1);
	// rldicr r8,r8,8,63
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r8.u64, 8) & 0xFFFFFFFFFFFFFFFF;
	// lbz r5,2(r11)
	ctx.r5.u64 = REX_LOAD_U8(ctx.r11.u32 + 2);
	// lbz r6,3(r11)
	ctx.r6.u64 = REX_LOAD_U8(ctx.r11.u32 + 3);
	// add r9,r9,r8
	ctx.r9.u64 = ctx.r9.u64 + ctx.r8.u64;
	// lbz r8,5(r11)
	ctx.r8.u64 = REX_LOAD_U8(ctx.r11.u32 + 5);
	// lbz r7,4(r11)
	ctx.r7.u64 = REX_LOAD_U8(ctx.r11.u32 + 4);
	// rldicr r11,r9,8,55
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r9.u64, 8) & 0xFFFFFFFFFFFFFF00;
	// lwz r10,8(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 8);
	// ld r9,0(r31)
	ctx.r9.u64 = REX_LOAD_U64(ctx.r31.u32 + 0);
	// add r11,r11,r5
	ctx.r11.u64 = ctx.r11.u64 + ctx.r5.u64;
	// stw r4,12(r31)
	REX_STORE_U32(ctx.r31.u32 + 12, ctx.r4.u32);
	// rldicr r11,r11,8,55
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u64, 8) & 0xFFFFFFFFFFFFFF00;
	// add r11,r11,r6
	ctx.r11.u64 = ctx.r11.u64 + ctx.r6.u64;
	// rldicr r11,r11,8,55
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u64, 8) & 0xFFFFFFFFFFFFFF00;
	// add r11,r11,r7
	ctx.r11.u64 = ctx.r11.u64 + ctx.r7.u64;
	// rldicr r11,r11,8,55
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u64, 8) & 0xFFFFFFFFFFFFFF00;
	// add r11,r11,r8
	ctx.r11.u64 = ctx.r11.u64 + ctx.r8.u64;
	// neg r8,r10
	ctx.r8.s64 = static_cast<int64_t>(-ctx.r10.u64);
	// addi r10,r10,48
	ctx.r10.s64 = ctx.r10.s64 + 48;
	// extsw r8,r8
	ctx.r8.s64 = ctx.r8.s32;
	// stw r10,8(r31)
	REX_STORE_U32(ctx.r31.u32 + 8, ctx.r10.u32);
	// sld r11,r11,r8
	ctx.r11.u64 = ctx.r8.u8 & 0x40 ? 0 : (ctx.r11.u64 << (ctx.r8.u8 & 0x7F));
	// add r11,r11,r9
	ctx.r11.u64 = ctx.r11.u64 + ctx.r9.u64;
	// std r11,0(r31)
	REX_STORE_U64(ctx.r31.u32 + 0, ctx.r11.u64);
loc_8290ECA0:
	// srawi r30,r30,4
	ctx.xer.ca = (ctx.r30.s32 < 0) & ((ctx.r30.u32 & 0xF) != 0);
	ctx.r30.s64 = ctx.r30.s32 >> 4;
	// b 0x8290ece4
	goto loc_8290ECE4;
loc_8290ECA8:
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x824c45b8
	ctx.lr = 0x8290ECB0;
	sub_824C45B8(ctx, base);
loc_8290ECB0:
	// ld r11,0(r31)
	ctx.r11.u64 = REX_LOAD_U64(ctx.r31.u32 + 0);
	// li r4,1
	ctx.r4.s64 = 1;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// rldicl r11,r11,1,63
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u64, 1) & 0x1;
	// rotlwi r28,r11,0
	ctx.r28.u64 = __builtin_rotateleft32(ctx.r11.u32, 0);
	// bl 0x824c45b8
	ctx.lr = 0x8290ECC8;
	sub_824C45B8(ctx, base);
	// add r11,r30,r28
	ctx.r11.u64 = ctx.r30.u64 + ctx.r28.u64;
	// add r11,r11,r15
	ctx.r11.u64 = ctx.r11.u64 + ctx.r15.u64;
	// rlwinm r11,r11,1,0,30
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 1) & 0xFFFFFFFE;
	// lhzx r11,r11,r29
	ctx.r11.u64 = REX_LOAD_U16(ctx.r11.u32 + ctx.r29.u32);
	// extsh r30,r11
	ctx.r30.s64 = ctx.r11.s16;
	// cmpwi cr6,r30,0
	ctx.cr6.compare<int32_t>(ctx.r30.s32, 0, ctx.xer);
	// blt cr6,0x8290ecb0
	if (ctx.cr6.lt) goto loc_8290ECB0;
loc_8290ECE4:
	// clrlwi r30,r30,16
	ctx.r30.u64 = ctx.r30.u32 & 0xFFFF;
	// lwz r11,92(r1)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r1.u32 + 92);
	// mr r28,r30
	ctx.r28.u64 = ctx.r30.u64;
	// cmpw cr6,r28,r11
	ctx.cr6.compare<int32_t>(ctx.r28.s32, ctx.r11.s32, ctx.xer);
	// beq cr6,0x8290ee30
	if (ctx.cr6.eq) goto loc_8290EE30;
	// cmplwi cr6,r28,0
	ctx.cr6.compare<uint32_t>(ctx.r28.u32, 0, ctx.xer);
	// beq cr6,0x8290ef54
	if (ctx.cr6.eq) goto loc_8290EF54;
	// lwz r11,96(r1)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r1.u32 + 96);
	// cmpwi cr6,r11,4
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 4, ctx.xer);
	// bne cr6,0x8290ed48
	if (!ctx.cr6.eq) goto loc_8290ED48;
	// ld r11,0(r31)
	ctx.r11.u64 = REX_LOAD_U64(ctx.r31.u32 + 0);
	// lwz r10,8(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 8);
	// rldicr r9,r11,1,62
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r11.u64, 1) & 0xFFFFFFFFFFFFFFFE;
	// addic. r10,r10,-1
	ctx.xer.ca = ctx.r10.u32 > 0;
	ctx.r10.s64 = ctx.r10.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// rldicl r11,r11,1,63
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u64, 1) & 0x1;
	// rotlwi r30,r11,0
	ctx.r30.u64 = __builtin_rotateleft32(ctx.r11.u32, 0);
	// std r9,0(r31)
	REX_STORE_U64(ctx.r31.u32 + 0, ctx.r9.u64);
	// stw r10,8(r31)
	REX_STORE_U32(ctx.r31.u32 + 8, ctx.r10.u32);
	// bge 0x8290ed38
	if (!ctx.cr0.lt) goto loc_8290ED38;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x824c44e8
	ctx.lr = 0x8290ED38;
	sub_824C44E8(ctx, base);
loc_8290ED38:
	// rlwinm r11,r28,1,0,30
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r28.u32 | (ctx.r28.u64 << 32), 1) & 0xFFFFFFFE;
	// add r11,r11,r30
	ctx.r11.u64 = ctx.r11.u64 + ctx.r30.u64;
	// add r11,r11,r21
	ctx.r11.u64 = ctx.r11.u64 + ctx.r21.u64;
	// b 0x8290ee0c
	goto loc_8290EE0C;
loc_8290ED48:
	// cmpwi cr6,r11,2
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 2, ctx.xer);
	// bne cr6,0x8290ee10
	if (!ctx.cr6.eq) goto loc_8290EE10;
	// lwz r11,8(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 8);
	// li r30,2
	ctx.r30.s64 = 2;
	// mr r29,r14
	ctx.r29.u64 = ctx.r14.u64;
	// addi r11,r11,16
	ctx.r11.s64 = ctx.r11.s64 + 16;
	// cmplwi cr6,r11,2
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 2, ctx.xer);
	// bge cr6,0x8290edc4
	if (!ctx.cr6.lt) goto loc_8290EDC4;
loc_8290ED68:
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x8290edc4
	if (ctx.cr6.eq) goto loc_8290EDC4;
	// subfic r8,r11,64
	ctx.xer.ca = ctx.r11.u32 <= 64;
	ctx.r8.u64 = static_cast<uint64_t>(64) - ctx.r11.u64;
	// lwz r9,8(r31)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r31.u32 + 8);
	// ld r10,0(r31)
	ctx.r10.u64 = REX_LOAD_U64(ctx.r31.u32 + 0);
	// subf r30,r11,r30
	ctx.r30.u64 = ctx.r30.u64 - ctx.r11.u64;
	// clrldi r8,r8,32
	ctx.r8.u64 = ctx.r8.u64 & 0xFFFFFFFF;
	// subf. r9,r11,r9
	ctx.r9.u64 = ctx.r9.u64 - ctx.r11.u64;
	ctx.cr0.compare<int32_t>(ctx.r9.s32, 0, ctx.xer);
	// clrldi r11,r11,32
	ctx.r11.u64 = ctx.r11.u64 & 0xFFFFFFFF;
	// stw r9,8(r31)
	REX_STORE_U32(ctx.r31.u32 + 8, ctx.r9.u32);
	// srd r8,r10,r8
	ctx.r8.u64 = ctx.r8.u8 & 0x40 ? 0 : (ctx.r10.u64 >> (ctx.r8.u8 & 0x7F));
	// sld r11,r10,r11
	ctx.r11.u64 = ctx.r11.u8 & 0x40 ? 0 : (ctx.r10.u64 << (ctx.r11.u8 & 0x7F));
	// rotlwi r10,r8,0
	ctx.r10.u64 = __builtin_rotateleft32(ctx.r8.u32, 0);
	// std r11,0(r31)
	REX_STORE_U64(ctx.r31.u32 + 0, ctx.r11.u64);
	// slw r11,r10,r30
	ctx.r11.u64 = ctx.r30.u8 & 0x20 ? 0 : (ctx.r10.u32 << (ctx.r30.u8 & 0x3F));
	// add r29,r11,r29
	ctx.r29.u64 = ctx.r11.u64 + ctx.r29.u64;
	// bge 0x8290edb4
	if (!ctx.cr0.lt) goto loc_8290EDB4;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x824c44e8
	ctx.lr = 0x8290EDB4;
	sub_824C44E8(ctx, base);
loc_8290EDB4:
	// lwz r11,8(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 8);
	// addi r11,r11,16
	ctx.r11.s64 = ctx.r11.s64 + 16;
	// cmplw cr6,r30,r11
	ctx.cr6.compare<uint32_t>(ctx.r30.u32, ctx.r11.u32, ctx.xer);
	// bgt cr6,0x8290ed68
	if (ctx.cr6.gt) goto loc_8290ED68;
loc_8290EDC4:
	// subfic r9,r30,64
	ctx.xer.ca = ctx.r30.u32 <= 64;
	ctx.r9.u64 = static_cast<uint64_t>(64) - ctx.r30.u64;
	// ld r11,0(r31)
	ctx.r11.u64 = REX_LOAD_U64(ctx.r31.u32 + 0);
	// clrldi r8,r30,32
	ctx.r8.u64 = ctx.r30.u64 & 0xFFFFFFFF;
	// lwz r10,8(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 8);
	// clrldi r9,r9,32
	ctx.r9.u64 = ctx.r9.u64 & 0xFFFFFFFF;
	// subf. r10,r30,r10
	ctx.r10.u64 = ctx.r10.u64 - ctx.r30.u64;
	ctx.cr0.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// stw r10,8(r31)
	REX_STORE_U32(ctx.r31.u32 + 8, ctx.r10.u32);
	// sld r8,r11,r8
	ctx.r8.u64 = ctx.r8.u8 & 0x40 ? 0 : (ctx.r11.u64 << (ctx.r8.u8 & 0x7F));
	// srd r9,r11,r9
	ctx.r9.u64 = ctx.r9.u8 & 0x40 ? 0 : (ctx.r11.u64 >> (ctx.r9.u8 & 0x7F));
	// rotlwi r11,r9,0
	ctx.r11.u64 = __builtin_rotateleft32(ctx.r9.u32, 0);
	// add r30,r11,r29
	ctx.r30.u64 = ctx.r11.u64 + ctx.r29.u64;
	// std r8,0(r31)
	REX_STORE_U64(ctx.r31.u32 + 0, ctx.r8.u64);
	// bge 0x8290ee00
	if (!ctx.cr0.lt) goto loc_8290EE00;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x824c44e8
	ctx.lr = 0x8290EE00;
	sub_824C44E8(ctx, base);
loc_8290EE00:
	// rlwinm r11,r28,2,0,29
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r28.u32 | (ctx.r28.u64 << 32), 2) & 0xFFFFFFFC;
	// add r11,r11,r30
	ctx.r11.u64 = ctx.r11.u64 + ctx.r30.u64;
	// add r11,r11,r20
	ctx.r11.u64 = ctx.r11.u64 + ctx.r20.u64;
loc_8290EE0C:
	// clrlwi r30,r11,16
	ctx.r30.u64 = ctx.r11.u32 & 0xFFFF;
loc_8290EE10:
	// ld r11,0(r31)
	ctx.r11.u64 = REX_LOAD_U64(ctx.r31.u32 + 0);
	// lwz r10,8(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 8);
	// rldicl r8,r11,1,63
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r11.u64, 1) & 0x1;
	// rldicr r9,r11,1,62
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r11.u64, 1) & 0xFFFFFFFFFFFFFFFE;
	// addic. r11,r10,-1
	ctx.xer.ca = ctx.r10.u32 > 0;
	ctx.r11.s64 = ctx.r10.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// rotlwi r29,r8,0
	ctx.r29.u64 = __builtin_rotateleft32(ctx.r8.u32, 0);
	// stw r11,8(r31)
	REX_STORE_U32(ctx.r31.u32 + 8, ctx.r11.u32);
	// b 0x8290ef30
	goto loc_8290EF30;
loc_8290EE30:
	// lwz r11,96(r1)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r1.u32 + 96);
	// cmpwi cr6,r11,4
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 4, ctx.xer);
	// bgt cr6,0x8290ee48
	if (ctx.cr6.gt) goto loc_8290EE48;
	// srawi r11,r11,1
	ctx.xer.ca = (ctx.r11.s32 < 0) & ((ctx.r11.u32 & 0x1) != 0);
	ctx.r11.s64 = ctx.r11.s32 >> 1;
	// subfic r11,r11,3
	ctx.xer.ca = ctx.r11.u32 <= 3;
	ctx.r11.u64 = static_cast<uint64_t>(3) - ctx.r11.u64;
	// b 0x8290ee4c
	goto loc_8290EE4C;
loc_8290EE48:
	// mr r11,r14
	ctx.r11.u64 = ctx.r14.u64;
loc_8290EE4C:
	// addi r30,r11,8
	ctx.r30.s64 = ctx.r11.s64 + 8;
	// lwz r11,8(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 8);
	// mr r29,r14
	ctx.r29.u64 = ctx.r14.u64;
	// cmplwi cr6,r30,0
	ctx.cr6.compare<uint32_t>(ctx.r30.u32, 0, ctx.xer);
	// addi r11,r11,16
	ctx.r11.s64 = ctx.r11.s64 + 16;
	// bne cr6,0x8290ee6c
	if (!ctx.cr6.eq) goto loc_8290EE6C;
	// mr r11,r14
	ctx.r11.u64 = ctx.r14.u64;
	// b 0x8290ef10
	goto loc_8290EF10;
loc_8290EE6C:
	// cmplw cr6,r30,r11
	ctx.cr6.compare<uint32_t>(ctx.r30.u32, ctx.r11.u32, ctx.xer);
	// ble cr6,0x8290eed0
	if (!ctx.cr6.gt) goto loc_8290EED0;
loc_8290EE74:
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x8290eed0
	if (ctx.cr6.eq) goto loc_8290EED0;
	// subfic r8,r11,64
	ctx.xer.ca = ctx.r11.u32 <= 64;
	ctx.r8.u64 = static_cast<uint64_t>(64) - ctx.r11.u64;
	// lwz r9,8(r31)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r31.u32 + 8);
	// ld r10,0(r31)
	ctx.r10.u64 = REX_LOAD_U64(ctx.r31.u32 + 0);
	// subf r30,r11,r30
	ctx.r30.u64 = ctx.r30.u64 - ctx.r11.u64;
	// clrldi r8,r8,32
	ctx.r8.u64 = ctx.r8.u64 & 0xFFFFFFFF;
	// subf. r9,r11,r9
	ctx.r9.u64 = ctx.r9.u64 - ctx.r11.u64;
	ctx.cr0.compare<int32_t>(ctx.r9.s32, 0, ctx.xer);
	// clrldi r11,r11,32
	ctx.r11.u64 = ctx.r11.u64 & 0xFFFFFFFF;
	// stw r9,8(r31)
	REX_STORE_U32(ctx.r31.u32 + 8, ctx.r9.u32);
	// srd r8,r10,r8
	ctx.r8.u64 = ctx.r8.u8 & 0x40 ? 0 : (ctx.r10.u64 >> (ctx.r8.u8 & 0x7F));
	// sld r11,r10,r11
	ctx.r11.u64 = ctx.r11.u8 & 0x40 ? 0 : (ctx.r10.u64 << (ctx.r11.u8 & 0x7F));
	// rotlwi r10,r8,0
	ctx.r10.u64 = __builtin_rotateleft32(ctx.r8.u32, 0);
	// std r11,0(r31)
	REX_STORE_U64(ctx.r31.u32 + 0, ctx.r11.u64);
	// slw r11,r10,r30
	ctx.r11.u64 = ctx.r30.u8 & 0x20 ? 0 : (ctx.r10.u32 << (ctx.r30.u8 & 0x3F));
	// add r29,r11,r29
	ctx.r29.u64 = ctx.r11.u64 + ctx.r29.u64;
	// bge 0x8290eec0
	if (!ctx.cr0.lt) goto loc_8290EEC0;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x824c44e8
	ctx.lr = 0x8290EEC0;
	sub_824C44E8(ctx, base);
loc_8290EEC0:
	// lwz r11,8(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 8);
	// addi r11,r11,16
	ctx.r11.s64 = ctx.r11.s64 + 16;
	// cmplw cr6,r30,r11
	ctx.cr6.compare<uint32_t>(ctx.r30.u32, ctx.r11.u32, ctx.xer);
	// bgt cr6,0x8290ee74
	if (ctx.cr6.gt) goto loc_8290EE74;
loc_8290EED0:
	// subfic r9,r30,64
	ctx.xer.ca = ctx.r30.u32 <= 64;
	ctx.r9.u64 = static_cast<uint64_t>(64) - ctx.r30.u64;
	// ld r11,0(r31)
	ctx.r11.u64 = REX_LOAD_U64(ctx.r31.u32 + 0);
	// clrldi r8,r30,32
	ctx.r8.u64 = ctx.r30.u64 & 0xFFFFFFFF;
	// lwz r10,8(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 8);
	// clrldi r9,r9,32
	ctx.r9.u64 = ctx.r9.u64 & 0xFFFFFFFF;
	// subf. r10,r30,r10
	ctx.r10.u64 = ctx.r10.u64 - ctx.r30.u64;
	ctx.cr0.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// stw r10,8(r31)
	REX_STORE_U32(ctx.r31.u32 + 8, ctx.r10.u32);
	// sld r8,r11,r8
	ctx.r8.u64 = ctx.r8.u8 & 0x40 ? 0 : (ctx.r11.u64 << (ctx.r8.u8 & 0x7F));
	// srd r9,r11,r9
	ctx.r9.u64 = ctx.r9.u8 & 0x40 ? 0 : (ctx.r11.u64 >> (ctx.r9.u8 & 0x7F));
	// rotlwi r11,r9,0
	ctx.r11.u64 = __builtin_rotateleft32(ctx.r9.u32, 0);
	// add r30,r11,r29
	ctx.r30.u64 = ctx.r11.u64 + ctx.r29.u64;
	// std r8,0(r31)
	REX_STORE_U64(ctx.r31.u32 + 0, ctx.r8.u64);
	// bge 0x8290ef0c
	if (!ctx.cr0.lt) goto loc_8290EF0C;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x824c44e8
	ctx.lr = 0x8290EF0C;
	sub_824C44E8(ctx, base);
loc_8290EF0C:
	// mr r11,r30
	ctx.r11.u64 = ctx.r30.u64;
loc_8290EF10:
	// lwz r10,8(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 8);
	// clrlwi r30,r11,16
	ctx.r30.u64 = ctx.r11.u32 & 0xFFFF;
	// ld r11,0(r31)
	ctx.r11.u64 = REX_LOAD_U64(ctx.r31.u32 + 0);
	// addic. r10,r10,-1
	ctx.xer.ca = ctx.r10.u32 > 0;
	ctx.r10.s64 = ctx.r10.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// rldicr r9,r11,1,62
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r11.u64, 1) & 0xFFFFFFFFFFFFFFFE;
	// rldicl r11,r11,1,63
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u64, 1) & 0x1;
	// rotlwi r29,r11,0
	ctx.r29.u64 = __builtin_rotateleft32(ctx.r11.u32, 0);
	// stw r10,8(r31)
	REX_STORE_U32(ctx.r31.u32 + 8, ctx.r10.u32);
loc_8290EF30:
	// std r9,0(r31)
	REX_STORE_U64(ctx.r31.u32 + 0, ctx.r9.u64);
	// bge 0x8290ef40
	if (!ctx.cr0.lt) goto loc_8290EF40;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x824c44e8
	ctx.lr = 0x8290EF40;
	sub_824C44E8(ctx, base);
loc_8290EF40:
	// rlwinm r11,r29,1,0,30
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r29.u32 | (ctx.r29.u64 << 32), 1) & 0xFFFFFFFE;
	// extsh r10,r30
	ctx.r10.s64 = ctx.r30.s16;
	// subfic r11,r11,1
	ctx.xer.ca = ctx.r11.u32 <= 1;
	ctx.r11.u64 = static_cast<uint64_t>(1) - ctx.r11.u64;
	// mullw r11,r11,r10
	ctx.r11.s64 = int64_t(ctx.r11.s32) * int64_t(ctx.r10.s32);
	// extsh r27,r11
	ctx.r27.s64 = ctx.r11.s16;
loc_8290EF54:
	// lwz r5,128(r1)
	ctx.r5.u64 = REX_LOAD_U32(ctx.r1.u32 + 128);
	// sth r27,0(r5)
	REX_STORE_U16(ctx.r5.u32 + 0, ctx.r27.u16);
	// lwz r11,0(r18)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r18.u32 + 0);
	// lwz r11,20(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 20);
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// bne cr6,0x8290f580
	if (!ctx.cr6.eq) goto loc_8290F580;
	// lwz r11,132(r1)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r1.u32 + 132);
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq cr6,0x8290ef94
	if (ctx.cr6.eq) goto loc_8290EF94;
	// lwz r11,100(r1)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r1.u32 + 100);
	// mr r3,r18
	ctx.r3.u64 = ctx.r18.u64;
	// lwz r6,192(r18)
	ctx.r6.u64 = REX_LOAD_U32(ctx.r18.u32 + 192);
	// lwz r4,0(r11)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r11.u32 + 0);
	// bl 0x828f8bd0
	ctx.lr = 0x8290EF8C;
	sub_828F8BD0(ctx, base);
	// cmpwi cr6,r3,0
	ctx.cr6.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// blt cr6,0x8290f580
	if (ctx.cr6.lt) goto loc_8290F580;
loc_8290EF94:
	// addi r25,r25,1
	ctx.r25.s64 = ctx.r25.s64 + 1;
	// rlwinm r24,r24,31,25,31
	ctx.r24.u64 = __builtin_rotateleft64(ctx.r24.u32 | (ctx.r24.u64 << 32), 31) & 0x7F;
	// cmpwi cr6,r25,6
	ctx.cr6.compare<int32_t>(ctx.r25.s32, 6, ctx.xer);
	// blt cr6,0x8290eb64
	if (ctx.cr6.lt) goto loc_8290EB64;
	// lwz r17,108(r1)
	ctx.r17.u64 = REX_LOAD_U32(ctx.r1.u32 + 108);
	// lwz r16,136(r1)
	ctx.r16.u64 = REX_LOAD_U32(ctx.r1.u32 + 136);
	// lwz r11,0(r17)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r17.u32 + 0);
	// lbz r9,4(r17)
	ctx.r9.u64 = REX_LOAD_U8(ctx.r17.u32 + 4);
	// clrlwi r11,r11,1
	ctx.r11.u64 = ctx.r11.u32 & 0x7FFFFFFF;
	// lbz r8,5(r17)
	ctx.r8.u64 = REX_LOAD_U8(ctx.r17.u32 + 5);
	// rlwinm r10,r11,0,27,28
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 0) & 0x18;
	// cntlzw r10,r10
	ctx.r10.u64 = ctx.r10.u32 == 0 ? 32 : __builtin_clz(ctx.r10.u32);
	// stw r11,0(r17)
	REX_STORE_U32(ctx.r17.u32 + 0, ctx.r11.u32);
	// rlwinm r10,r10,1,25,25
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 1) & 0x40;
	// lwz r11,132(r18)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r18.u32 + 132);
	// or r10,r10,r9
	ctx.r10.u64 = ctx.r10.u64 | ctx.r9.u64;
	// rlwinm r7,r11,3,0,28
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 3) & 0xFFFFFFF8;
	// lwz r11,1132(r18)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r18.u32 + 1132);
	// rlwinm r10,r10,8,16,23
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 8) & 0xFF00;
	// or r10,r10,r8
	ctx.r10.u64 = ctx.r10.u64 | ctx.r8.u64;
	// rldicr r10,r10,48,15
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u64, 48) & 0xFFFF000000000000;
	// stdx r10,r7,r11
	REX_STORE_U64(ctx.r7.u32 + ctx.r11.u32, ctx.r10.u64);
	// b 0x8290f49c
	goto loc_8290F49C;
loc_8290EFF0:
	// lbz r10,21(r18)
	ctx.r10.u64 = REX_LOAD_U8(ctx.r18.u32 + 21);
	// mr r24,r14
	ctx.r24.u64 = ctx.r14.u64;
	// lwz r11,0(r17)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r17.u32 + 0);
	// lbz r25,26(r18)
	ctx.r25.u64 = REX_LOAD_U8(ctx.r18.u32 + 26);
	// mr r27,r10
	ctx.r27.u64 = ctx.r10.u64;
	// lbz r20,5(r17)
	ctx.r20.u64 = REX_LOAD_U8(ctx.r17.u32 + 5);
	// rlwinm r23,r11,12,30,31
	ctx.r23.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 12) & 0x3;
	// rlwinm r19,r11,4,31,31
	ctx.r19.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 4) & 0x1;
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// beq cr6,0x8290f01c
	if (ctx.cr6.eq) goto loc_8290F01C;
	// rlwinm r25,r11,8,29,31
	ctx.r25.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 8) & 0x7;
loc_8290F01C:
	// lbz r10,20(r18)
	ctx.r10.u64 = REX_LOAD_U8(ctx.r18.u32 + 20);
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// beq cr6,0x8290f038
	if (ctx.cr6.eq) goto loc_8290F038;
	// lwz r10,160(r18)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r18.u32 + 160);
	// rlwinm r11,r11,12,28,29
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 12) & 0xC;
	// add r22,r11,r10
	ctx.r22.u64 = ctx.r11.u64 + ctx.r10.u64;
	// b 0x8290f03c
	goto loc_8290F03C;
loc_8290F038:
	// lwz r22,168(r18)
	ctx.r22.u64 = REX_LOAD_U32(ctx.r18.u32 + 168);
loc_8290F03C:
	// mr r21,r14
	ctx.r21.u64 = ctx.r14.u64;
loc_8290F040:
	// clrlwi r11,r20,31
	ctx.r11.u64 = ctx.r20.u32 & 0x1;
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq cr6,0x8290f434
	if (ctx.cr6.eq) goto loc_8290F434;
	// addi r11,r27,-1
	ctx.r11.s64 = ctx.r27.s64 + -1;
	// and r11,r11,r19
	ctx.r11.u64 = ctx.r11.u64 & ctx.r19.u64;
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x8290f1a4
	if (ctx.cr6.eq) goto loc_8290F1A4;
	// lwz r31,0(r18)
	ctx.r31.u64 = REX_LOAD_U32(ctx.r18.u32 + 0);
	// lwz r11,296(r18)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r18.u32 + 296);
	// ld r9,0(r31)
	ctx.r9.u64 = REX_LOAD_U64(ctx.r31.u32 + 0);
	// lwz r28,0(r11)
	ctx.r28.u64 = REX_LOAD_U32(ctx.r11.u32 + 0);
	// rldicl r11,r9,6,58
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r9.u64, 6) & 0x3F;
	// rlwinm r11,r11,1,0,30
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 1) & 0xFFFFFFFE;
	// lhzx r11,r11,r28
	ctx.r11.u64 = REX_LOAD_U16(ctx.r11.u32 + ctx.r28.u32);
	// extsh r30,r11
	ctx.r30.s64 = ctx.r11.s16;
	// cmpwi cr6,r30,0
	ctx.cr6.compare<int32_t>(ctx.r30.s32, 0, ctx.xer);
	// blt cr6,0x8290f144
	if (ctx.cr6.lt) goto loc_8290F144;
	// clrlwi r11,r30,28
	ctx.r11.u64 = ctx.r30.u32 & 0xF;
	// lwz r10,8(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 8);
	// cmpw cr6,r10,r11
	ctx.cr6.compare<int32_t>(ctx.r10.s32, ctx.r11.s32, ctx.xer);
	// sld r9,r9,r11
	ctx.r9.u64 = ctx.r11.u8 & 0x40 ? 0 : (ctx.r9.u64 << (ctx.r11.u8 & 0x7F));
	// std r9,0(r31)
	REX_STORE_U64(ctx.r31.u32 + 0, ctx.r9.u64);
	// subf r9,r11,r10
	ctx.r9.u64 = ctx.r10.u64 - ctx.r11.u64;
	// stw r9,8(r31)
	REX_STORE_U32(ctx.r31.u32 + 8, ctx.r9.u32);
	// bge cr6,0x8290f13c
	if (!ctx.cr6.lt) goto loc_8290F13C;
loc_8290F0A4:
	// lwz r10,16(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 16);
	// lwz r11,12(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 12);
	// addi r10,r10,-4
	ctx.r10.s64 = ctx.r10.s64 + -4;
	// cmplw cr6,r11,r10
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, ctx.r10.u32, ctx.xer);
	// blt cr6,0x8290f0d0
	if (ctx.cr6.lt) goto loc_8290F0D0;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x824c4428
	ctx.lr = 0x8290F0C0;
	sub_824C4428(ctx, base);
	// cmplwi cr6,r3,1
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 1, ctx.xer);
	// beq cr6,0x8290f0a4
	if (ctx.cr6.eq) goto loc_8290F0A4;
	// srawi r30,r30,4
	ctx.xer.ca = (ctx.r30.s32 < 0) & ((ctx.r30.u32 & 0xF) != 0);
	ctx.r30.s64 = ctx.r30.s32 >> 4;
	// b 0x8290f184
	goto loc_8290F184;
loc_8290F0D0:
	// lbz r9,0(r11)
	ctx.r9.u64 = REX_LOAD_U8(ctx.r11.u32 + 0);
	// addi r4,r11,6
	ctx.r4.s64 = ctx.r11.s64 + 6;
	// lbz r8,1(r11)
	ctx.r8.u64 = REX_LOAD_U8(ctx.r11.u32 + 1);
	// rldicr r9,r9,8,63
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r9.u64, 8) & 0xFFFFFFFFFFFFFFFF;
	// lbz r5,2(r11)
	ctx.r5.u64 = REX_LOAD_U8(ctx.r11.u32 + 2);
	// lbz r6,3(r11)
	ctx.r6.u64 = REX_LOAD_U8(ctx.r11.u32 + 3);
	// add r9,r9,r8
	ctx.r9.u64 = ctx.r9.u64 + ctx.r8.u64;
	// lbz r8,5(r11)
	ctx.r8.u64 = REX_LOAD_U8(ctx.r11.u32 + 5);
	// lbz r7,4(r11)
	ctx.r7.u64 = REX_LOAD_U8(ctx.r11.u32 + 4);
	// rldicr r11,r9,8,55
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r9.u64, 8) & 0xFFFFFFFFFFFFFF00;
	// lwz r10,8(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 8);
	// ld r9,0(r31)
	ctx.r9.u64 = REX_LOAD_U64(ctx.r31.u32 + 0);
	// add r11,r11,r5
	ctx.r11.u64 = ctx.r11.u64 + ctx.r5.u64;
	// stw r4,12(r31)
	REX_STORE_U32(ctx.r31.u32 + 12, ctx.r4.u32);
	// rldicr r11,r11,8,55
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u64, 8) & 0xFFFFFFFFFFFFFF00;
	// add r11,r11,r6
	ctx.r11.u64 = ctx.r11.u64 + ctx.r6.u64;
	// rldicr r11,r11,8,55
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u64, 8) & 0xFFFFFFFFFFFFFF00;
	// add r11,r11,r7
	ctx.r11.u64 = ctx.r11.u64 + ctx.r7.u64;
	// rldicr r11,r11,8,55
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u64, 8) & 0xFFFFFFFFFFFFFF00;
	// add r11,r11,r8
	ctx.r11.u64 = ctx.r11.u64 + ctx.r8.u64;
	// neg r8,r10
	ctx.r8.s64 = static_cast<int64_t>(-ctx.r10.u64);
	// addi r10,r10,48
	ctx.r10.s64 = ctx.r10.s64 + 48;
	// extsw r8,r8
	ctx.r8.s64 = ctx.r8.s32;
	// stw r10,8(r31)
	REX_STORE_U32(ctx.r31.u32 + 8, ctx.r10.u32);
	// sld r11,r11,r8
	ctx.r11.u64 = ctx.r8.u8 & 0x40 ? 0 : (ctx.r11.u64 << (ctx.r8.u8 & 0x7F));
	// add r11,r11,r9
	ctx.r11.u64 = ctx.r11.u64 + ctx.r9.u64;
	// std r11,0(r31)
	REX_STORE_U64(ctx.r31.u32 + 0, ctx.r11.u64);
loc_8290F13C:
	// srawi r30,r30,4
	ctx.xer.ca = (ctx.r30.s32 < 0) & ((ctx.r30.u32 & 0xF) != 0);
	ctx.r30.s64 = ctx.r30.s32 >> 4;
	// b 0x8290f184
	goto loc_8290F184;
loc_8290F144:
	// li r4,6
	ctx.r4.s64 = 6;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x824c45b8
	ctx.lr = 0x8290F150;
	sub_824C45B8(ctx, base);
loc_8290F150:
	// ld r11,0(r31)
	ctx.r11.u64 = REX_LOAD_U64(ctx.r31.u32 + 0);
	// li r4,1
	ctx.r4.s64 = 1;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// rldicl r11,r11,1,63
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u64, 1) & 0x1;
	// rotlwi r29,r11,0
	ctx.r29.u64 = __builtin_rotateleft32(ctx.r11.u32, 0);
	// bl 0x824c45b8
	ctx.lr = 0x8290F168;
	sub_824C45B8(ctx, base);
	// add r11,r29,r30
	ctx.r11.u64 = ctx.r29.u64 + ctx.r30.u64;
	// add r11,r11,r15
	ctx.r11.u64 = ctx.r11.u64 + ctx.r15.u64;
	// rlwinm r11,r11,1,0,30
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 1) & 0xFFFFFFFE;
	// lhzx r11,r11,r28
	ctx.r11.u64 = REX_LOAD_U16(ctx.r11.u32 + ctx.r28.u32);
	// extsh r30,r11
	ctx.r30.s64 = ctx.r11.s16;
	// cmpwi cr6,r30,0
	ctx.cr6.compare<int32_t>(ctx.r30.s32, 0, ctx.xer);
	// blt cr6,0x8290f150
	if (ctx.cr6.lt) goto loc_8290F150;
loc_8290F184:
	// lwz r11,0(r18)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r18.u32 + 0);
	// lwz r11,20(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 20);
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// bne cr6,0x8290f580
	if (!ctx.cr6.eq) goto loc_8290F580;
	// add r11,r30,r18
	ctx.r11.u64 = ctx.r30.u64 + ctx.r18.u64;
	// add r10,r30,r18
	ctx.r10.u64 = ctx.r30.u64 + ctx.r18.u64;
	// lbz r25,372(r11)
	ctx.r25.u64 = REX_LOAD_U8(ctx.r11.u32 + 372);
	// lbz r23,380(r10)
	ctx.r23.u64 = REX_LOAD_U8(ctx.r10.u32 + 380);
loc_8290F1A4:
	// cmpwi cr6,r25,0
	ctx.cr6.compare<int32_t>(ctx.r25.s32, 0, ctx.xer);
	// bne cr6,0x8290f1e8
	if (!ctx.cr6.eq) goto loc_8290F1E8;
	// lwz r31,964(r18)
	ctx.r31.u64 = REX_LOAD_U32(ctx.r18.u32 + 964);
	// mr r3,r18
	ctx.r3.u64 = ctx.r18.u64;
	// lwz r4,0(r22)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r22.u32 + 0);
	// mr r6,r31
	ctx.r6.u64 = ctx.r31.u64;
	// lbz r5,780(r18)
	ctx.r5.u64 = REX_LOAD_U8(ctx.r18.u32 + 780);
	// bl 0x828f8810
	ctx.lr = 0x8290F1C4;
	sub_828F8810(ctx, base);
	// rlwinm r11,r3,1,24,30
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r3.u32 | (ctx.r3.u64 << 32), 1) & 0xFE;
	// ori r24,r24,1
	ctx.r24.u64 = ctx.r24.u64 | 1;
	// add r11,r11,r31
	ctx.r11.u64 = ctx.r11.u64 + ctx.r31.u64;
	// stw r11,964(r18)
	REX_STORE_U32(ctx.r18.u32 + 964, ctx.r11.u32);
	// lwz r11,968(r18)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r18.u32 + 968);
	// stb r3,0(r11)
	REX_STORE_U8(ctx.r11.u32 + 0, ctx.r3.u8);
	// lwz r11,968(r18)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r18.u32 + 968);
	// addi r11,r11,1
	ctx.r11.s64 = ctx.r11.s64 + 1;
	// b 0x8290f42c
	goto loc_8290F42C;
loc_8290F1E8:
	// cmpwi cr6,r25,2
	ctx.cr6.compare<int32_t>(ctx.r25.s32, 2, ctx.xer);
	// bgt cr6,0x8290f274
	if (ctx.cr6.gt) goto loc_8290F274;
	// or r11,r19,r27
	ctx.r11.u64 = ctx.r19.u64 | ctx.r27.u64;
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x8290f204
	if (ctx.cr6.eq) goto loc_8290F204;
	// mr r11,r23
	ctx.r11.u64 = ctx.r23.u64;
	// b 0x8290f3b0
	goto loc_8290F3B0;
loc_8290F204:
	// lwz r3,0(r18)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r18.u32 + 0);
	// ld r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U64(ctx.r3.u32 + 0);
	// lwz r10,8(r3)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r3.u32 + 8);
	// rldicr r9,r11,1,62
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r11.u64, 1) & 0xFFFFFFFFFFFFFFFE;
	// rldicl r8,r11,1,63
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r11.u64, 1) & 0x1;
	// addic. r11,r10,-1
	ctx.xer.ca = ctx.r10.u32 > 0;
	ctx.r11.s64 = ctx.r10.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// rotlwi r31,r8,0
	ctx.r31.u64 = __builtin_rotateleft32(ctx.r8.u32, 0);
	// std r9,0(r3)
	REX_STORE_U64(ctx.r3.u32 + 0, ctx.r9.u64);
	// stw r11,8(r3)
	REX_STORE_U32(ctx.r3.u32 + 8, ctx.r11.u32);
	// bge 0x8290f230
	if (!ctx.cr0.lt) goto loc_8290F230;
	// bl 0x824c44e8
	ctx.lr = 0x8290F230;
	sub_824C44E8(ctx, base);
loc_8290F230:
	// cmplwi cr6,r31,1
	ctx.cr6.compare<uint32_t>(ctx.r31.u32, 1, ctx.xer);
	// bne cr6,0x8290f26c
	if (!ctx.cr6.eq) goto loc_8290F26C;
	// lwz r3,0(r18)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r18.u32 + 0);
	// ld r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U64(ctx.r3.u32 + 0);
	// lwz r10,8(r3)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r3.u32 + 8);
	// rldicr r9,r11,1,62
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r11.u64, 1) & 0xFFFFFFFFFFFFFFFE;
	// rldicl r8,r11,1,63
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r11.u64, 1) & 0x1;
	// addic. r11,r10,-1
	ctx.xer.ca = ctx.r10.u32 > 0;
	ctx.r11.s64 = ctx.r10.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// rotlwi r31,r8,0
	ctx.r31.u64 = __builtin_rotateleft32(ctx.r8.u32, 0);
	// std r9,0(r3)
	REX_STORE_U64(ctx.r3.u32 + 0, ctx.r9.u64);
	// stw r11,8(r3)
	REX_STORE_U32(ctx.r3.u32 + 8, ctx.r11.u32);
	// bge 0x8290f264
	if (!ctx.cr0.lt) goto loc_8290F264;
	// bl 0x824c44e8
	ctx.lr = 0x8290F264;
	sub_824C44E8(ctx, base);
loc_8290F264:
	// addi r11,r31,1
	ctx.r11.s64 = ctx.r31.s64 + 1;
	// b 0x8290f3b0
	goto loc_8290F3B0;
loc_8290F26C:
	// li r11,3
	ctx.r11.s64 = 3;
	// b 0x8290f3b0
	goto loc_8290F3B0;
loc_8290F274:
	// lwz r31,0(r18)
	ctx.r31.u64 = REX_LOAD_U32(ctx.r18.u32 + 0);
	// lwz r11,300(r18)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r18.u32 + 300);
	// ld r9,0(r31)
	ctx.r9.u64 = REX_LOAD_U64(ctx.r31.u32 + 0);
	// lwz r28,0(r11)
	ctx.r28.u64 = REX_LOAD_U32(ctx.r11.u32 + 0);
	// rldicl r11,r9,6,58
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r9.u64, 6) & 0x3F;
	// rlwinm r11,r11,1,0,30
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 1) & 0xFFFFFFFE;
	// lhzx r11,r11,r28
	ctx.r11.u64 = REX_LOAD_U16(ctx.r11.u32 + ctx.r28.u32);
	// extsh r30,r11
	ctx.r30.s64 = ctx.r11.s16;
	// cmpwi cr6,r30,0
	ctx.cr6.compare<int32_t>(ctx.r30.s32, 0, ctx.xer);
	// blt cr6,0x8290f35c
	if (ctx.cr6.lt) goto loc_8290F35C;
	// clrlwi r11,r30,28
	ctx.r11.u64 = ctx.r30.u32 & 0xF;
	// lwz r10,8(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 8);
	// cmpw cr6,r10,r11
	ctx.cr6.compare<int32_t>(ctx.r10.s32, ctx.r11.s32, ctx.xer);
	// sld r9,r9,r11
	ctx.r9.u64 = ctx.r11.u8 & 0x40 ? 0 : (ctx.r9.u64 << (ctx.r11.u8 & 0x7F));
	// std r9,0(r31)
	REX_STORE_U64(ctx.r31.u32 + 0, ctx.r9.u64);
	// subf r9,r11,r10
	ctx.r9.u64 = ctx.r10.u64 - ctx.r11.u64;
	// stw r9,8(r31)
	REX_STORE_U32(ctx.r31.u32 + 8, ctx.r9.u32);
	// bge cr6,0x8290f354
	if (!ctx.cr6.lt) goto loc_8290F354;
loc_8290F2BC:
	// lwz r10,16(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 16);
	// lwz r11,12(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 12);
	// addi r10,r10,-4
	ctx.r10.s64 = ctx.r10.s64 + -4;
	// cmplw cr6,r11,r10
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, ctx.r10.u32, ctx.xer);
	// blt cr6,0x8290f2e8
	if (ctx.cr6.lt) goto loc_8290F2E8;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x824c4428
	ctx.lr = 0x8290F2D8;
	sub_824C4428(ctx, base);
	// cmplwi cr6,r3,1
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 1, ctx.xer);
	// beq cr6,0x8290f2bc
	if (ctx.cr6.eq) goto loc_8290F2BC;
	// srawi r30,r30,4
	ctx.xer.ca = (ctx.r30.s32 < 0) & ((ctx.r30.u32 & 0xF) != 0);
	ctx.r30.s64 = ctx.r30.s32 >> 4;
	// b 0x8290f39c
	goto loc_8290F39C;
loc_8290F2E8:
	// lbz r9,0(r11)
	ctx.r9.u64 = REX_LOAD_U8(ctx.r11.u32 + 0);
	// addi r4,r11,6
	ctx.r4.s64 = ctx.r11.s64 + 6;
	// lbz r8,1(r11)
	ctx.r8.u64 = REX_LOAD_U8(ctx.r11.u32 + 1);
	// rldicr r9,r9,8,63
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r9.u64, 8) & 0xFFFFFFFFFFFFFFFF;
	// lbz r5,2(r11)
	ctx.r5.u64 = REX_LOAD_U8(ctx.r11.u32 + 2);
	// lbz r6,3(r11)
	ctx.r6.u64 = REX_LOAD_U8(ctx.r11.u32 + 3);
	// add r9,r9,r8
	ctx.r9.u64 = ctx.r9.u64 + ctx.r8.u64;
	// lbz r8,5(r11)
	ctx.r8.u64 = REX_LOAD_U8(ctx.r11.u32 + 5);
	// lbz r7,4(r11)
	ctx.r7.u64 = REX_LOAD_U8(ctx.r11.u32 + 4);
	// rldicr r11,r9,8,55
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r9.u64, 8) & 0xFFFFFFFFFFFFFF00;
	// lwz r10,8(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 8);
	// ld r9,0(r31)
	ctx.r9.u64 = REX_LOAD_U64(ctx.r31.u32 + 0);
	// add r11,r11,r5
	ctx.r11.u64 = ctx.r11.u64 + ctx.r5.u64;
	// stw r4,12(r31)
	REX_STORE_U32(ctx.r31.u32 + 12, ctx.r4.u32);
	// rldicr r11,r11,8,55
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u64, 8) & 0xFFFFFFFFFFFFFF00;
	// add r11,r11,r6
	ctx.r11.u64 = ctx.r11.u64 + ctx.r6.u64;
	// rldicr r11,r11,8,55
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u64, 8) & 0xFFFFFFFFFFFFFF00;
	// add r11,r11,r7
	ctx.r11.u64 = ctx.r11.u64 + ctx.r7.u64;
	// rldicr r11,r11,8,55
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u64, 8) & 0xFFFFFFFFFFFFFF00;
	// add r11,r11,r8
	ctx.r11.u64 = ctx.r11.u64 + ctx.r8.u64;
	// neg r8,r10
	ctx.r8.s64 = static_cast<int64_t>(-ctx.r10.u64);
	// addi r10,r10,48
	ctx.r10.s64 = ctx.r10.s64 + 48;
	// extsw r8,r8
	ctx.r8.s64 = ctx.r8.s32;
	// stw r10,8(r31)
	REX_STORE_U32(ctx.r31.u32 + 8, ctx.r10.u32);
	// sld r11,r11,r8
	ctx.r11.u64 = ctx.r8.u8 & 0x40 ? 0 : (ctx.r11.u64 << (ctx.r8.u8 & 0x7F));
	// add r11,r11,r9
	ctx.r11.u64 = ctx.r11.u64 + ctx.r9.u64;
	// std r11,0(r31)
	REX_STORE_U64(ctx.r31.u32 + 0, ctx.r11.u64);
loc_8290F354:
	// srawi r30,r30,4
	ctx.xer.ca = (ctx.r30.s32 < 0) & ((ctx.r30.u32 & 0xF) != 0);
	ctx.r30.s64 = ctx.r30.s32 >> 4;
	// b 0x8290f39c
	goto loc_8290F39C;
loc_8290F35C:
	// li r4,6
	ctx.r4.s64 = 6;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x824c45b8
	ctx.lr = 0x8290F368;
	sub_824C45B8(ctx, base);
loc_8290F368:
	// ld r11,0(r31)
	ctx.r11.u64 = REX_LOAD_U64(ctx.r31.u32 + 0);
	// li r4,1
	ctx.r4.s64 = 1;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// rldicl r11,r11,1,63
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u64, 1) & 0x1;
	// rotlwi r29,r11,0
	ctx.r29.u64 = __builtin_rotateleft32(ctx.r11.u32, 0);
	// bl 0x824c45b8
	ctx.lr = 0x8290F380;
	sub_824C45B8(ctx, base);
	// add r11,r29,r30
	ctx.r11.u64 = ctx.r29.u64 + ctx.r30.u64;
	// add r11,r11,r15
	ctx.r11.u64 = ctx.r11.u64 + ctx.r15.u64;
	// rlwinm r11,r11,1,0,30
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 1) & 0xFFFFFFFE;
	// lhzx r11,r11,r28
	ctx.r11.u64 = REX_LOAD_U16(ctx.r11.u32 + ctx.r28.u32);
	// extsh r30,r11
	ctx.r30.s64 = ctx.r11.s16;
	// cmpwi cr6,r30,0
	ctx.cr6.compare<int32_t>(ctx.r30.s32, 0, ctx.xer);
	// blt cr6,0x8290f368
	if (ctx.cr6.lt) goto loc_8290F368;
loc_8290F39C:
	// lwz r10,0(r18)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r18.u32 + 0);
	// addi r11,r30,1
	ctx.r11.s64 = ctx.r30.s64 + 1;
	// lwz r10,20(r10)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r10.u32 + 20);
	// cmpwi cr6,r10,0
	ctx.cr6.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// bne cr6,0x8290f580
	if (!ctx.cr6.eq) goto loc_8290F580;
loc_8290F3B0:
	// add r9,r11,r18
	ctx.r9.u64 = ctx.r11.u64 + ctx.r18.u64;
	// lwz r28,0(r22)
	ctx.r28.u64 = REX_LOAD_U32(ctx.r22.u32 + 0);
	// rlwinm r10,r25,4,0,27
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r25.u32 | (ctx.r25.u64 << 32), 4) & 0xFFFFFFF0;
	// lwz r26,968(r18)
	ctx.r26.u64 = REX_LOAD_U32(ctx.r18.u32 + 968);
	// extsw r11,r11
	ctx.r11.s64 = ctx.r11.s32;
	// lwz r30,964(r18)
	ctx.r30.u64 = REX_LOAD_U32(ctx.r18.u32 + 964);
	// extsw r10,r10
	ctx.r10.s64 = ctx.r10.s32;
	// add r8,r25,r18
	ctx.r8.u64 = ctx.r25.u64 + ctx.r18.u64;
	// lbz r29,84(r9)
	ctx.r29.u64 = REX_LOAD_U8(ctx.r9.u32 + 84);
	// or r11,r10,r11
	ctx.r11.u64 = ctx.r10.u64 | ctx.r11.u64;
	// mr r31,r14
	ctx.r31.u64 = ctx.r14.u64;
	// or r24,r11,r24
	ctx.r24.u64 = ctx.r11.u64 | ctx.r24.u64;
	// cmpwi cr6,r29,0
	ctx.cr6.compare<int32_t>(ctx.r29.s32, 0, ctx.xer);
	// lbz r27,780(r8)
	ctx.r27.u64 = REX_LOAD_U8(ctx.r8.u32 + 780);
	// ble cr6,0x8290f418
	if (!ctx.cr6.gt) goto loc_8290F418;
loc_8290F3EC:
	// mr r6,r30
	ctx.r6.u64 = ctx.r30.u64;
	// mr r5,r27
	ctx.r5.u64 = ctx.r27.u64;
	// mr r4,r28
	ctx.r4.u64 = ctx.r28.u64;
	// mr r3,r18
	ctx.r3.u64 = ctx.r18.u64;
	// bl 0x828f8810
	ctx.lr = 0x8290F400;
	sub_828F8810(ctx, base);
	// stbx r3,r31,r26
	REX_STORE_U8(ctx.r31.u32 + ctx.r26.u32, ctx.r3.u8);
	// rlwinm r11,r3,1,24,30
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r3.u32 | (ctx.r3.u64 << 32), 1) & 0xFE;
	// addi r31,r31,1
	ctx.r31.s64 = ctx.r31.s64 + 1;
	// add r30,r11,r30
	ctx.r30.u64 = ctx.r11.u64 + ctx.r30.u64;
	// cmpw cr6,r31,r29
	ctx.cr6.compare<int32_t>(ctx.r31.s32, ctx.r29.s32, ctx.xer);
	// blt cr6,0x8290f3ec
	if (ctx.cr6.lt) goto loc_8290F3EC;
loc_8290F418:
	// cmpwi cr6,r30,-1
	ctx.cr6.compare<int32_t>(ctx.r30.s32, -1, ctx.xer);
	// beq cr6,0x8290f580
	if (ctx.cr6.eq) goto loc_8290F580;
	// lwz r11,968(r18)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r18.u32 + 968);
	// stw r30,964(r18)
	REX_STORE_U32(ctx.r18.u32 + 964, ctx.r30.u32);
	// add r11,r11,r29
	ctx.r11.u64 = ctx.r11.u64 + ctx.r29.u64;
loc_8290F42C:
	// stw r11,968(r18)
	REX_STORE_U32(ctx.r18.u32 + 968, ctx.r11.u32);
	// mr r27,r14
	ctx.r27.u64 = ctx.r14.u64;
loc_8290F434:
	// addi r21,r21,1
	ctx.r21.s64 = ctx.r21.s64 + 1;
	// rlwinm r20,r20,31,25,31
	ctx.r20.u64 = __builtin_rotateleft64(ctx.r20.u32 | (ctx.r20.u64 << 32), 31) & 0x7F;
	// rldicr r24,r24,8,55
	ctx.r24.u64 = __builtin_rotateleft64(ctx.r24.u64, 8) & 0xFFFFFFFFFFFFFF00;
	// cmpwi cr6,r21,6
	ctx.cr6.compare<int32_t>(ctx.r21.s32, 6, ctx.xer);
	// blt cr6,0x8290f040
	if (ctx.cr6.lt) goto loc_8290F040;
	// lwz r10,132(r18)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r18.u32 + 132);
	// rldicl r7,r24,56,8
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r24.u64, 56) & 0xFFFFFFFFFFFFFF;
	// lwz r11,0(r17)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r17.u32 + 0);
	// rlwinm r5,r10,3,0,28
	ctx.r5.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 3) & 0xFFFFFFF8;
	// lbz r8,5(r17)
	ctx.r8.u64 = REX_LOAD_U8(ctx.r17.u32 + 5);
	// rlwinm r10,r11,27,29,31
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 27) & 0x7;
	// lbz r6,4(r17)
	ctx.r6.u64 = REX_LOAD_U8(ctx.r17.u32 + 4);
	// rldicr r4,r11,0,32
	ctx.r4.u64 = __builtin_rotateleft64(ctx.r11.u64, 0) & 0xFFFFFFFF80000000;
	// lwz r9,1132(r18)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r18.u32 + 1132);
	// rlwinm r11,r10,6,0,25
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 6) & 0xFFFFFFC0;
	// rlwinm r10,r10,5,19,24
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 5) & 0x1F80;
	// or r11,r11,r8
	ctx.r11.u64 = ctx.r11.u64 | ctx.r8.u64;
	// or r10,r10,r6
	ctx.r10.u64 = ctx.r10.u64 | ctx.r6.u64;
	// clrldi r11,r11,56
	ctx.r11.u64 = ctx.r11.u64 & 0xFF;
	// rlwinm r10,r10,8,16,23
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 8) & 0xFF00;
	// or r11,r10,r11
	ctx.r11.u64 = ctx.r10.u64 | ctx.r11.u64;
	// rldicr r11,r11,32,31
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u64, 32) & 0xFFFFFFFF00000000;
	// or r11,r11,r4
	ctx.r11.u64 = ctx.r11.u64 | ctx.r4.u64;
	// rldicr r11,r11,16,47
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u64, 16) & 0xFFFFFFFFFFFF0000;
	// or r11,r11,r7
	ctx.r11.u64 = ctx.r11.u64 | ctx.r7.u64;
	// stdx r11,r5,r9
	REX_STORE_U64(ctx.r5.u32 + ctx.r9.u32, ctx.r11.u64);
loc_8290F49C:
	// lwz r11,104(r1)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r1.u32 + 104);
	// addi r17,r17,20
	ctx.r17.s64 = ctx.r17.s64 + 20;
	// lhz r10,270(r16)
	ctx.r10.u64 = REX_LOAD_U16(ctx.r16.u32 + 270);
	// addi r8,r11,1
	ctx.r8.s64 = ctx.r11.s64 + 1;
	// lwz r11,80(r1)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r1.u32 + 80);
	// addi r7,r10,2
	ctx.r7.s64 = ctx.r10.s64 + 2;
	// lwz r9,132(r16)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r16.u32 + 132);
	// addi r11,r11,1
	ctx.r11.s64 = ctx.r11.s64 + 1;
	// lwz r10,260(r16)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r16.u32 + 260);
	// addi r9,r9,1
	ctx.r9.s64 = ctx.r9.s64 + 1;
	// stw r17,108(r1)
	REX_STORE_U32(ctx.r1.u32 + 108, ctx.r17.u32);
	// addi r10,r10,16
	ctx.r10.s64 = ctx.r10.s64 + 16;
	// stw r8,104(r1)
	REX_STORE_U32(ctx.r1.u32 + 104, ctx.r8.u32);
	// sth r7,270(r16)
	REX_STORE_U16(ctx.r16.u32 + 270, ctx.r7.u16);
	// stw r11,80(r1)
	REX_STORE_U32(ctx.r1.u32 + 80, ctx.r11.u32);
	// lwz r11,128(r16)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r16.u32 + 128);
	// stw r9,132(r16)
	REX_STORE_U32(ctx.r16.u32 + 132, ctx.r9.u32);
	// addi r6,r11,2
	ctx.r6.s64 = ctx.r11.s64 + 2;
	// lwz r11,264(r16)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r16.u32 + 264);
	// stw r10,260(r16)
	REX_STORE_U32(ctx.r16.u32 + 260, ctx.r10.u32);
	// addi r11,r11,8
	ctx.r11.s64 = ctx.r11.s64 + 8;
	// stw r6,128(r16)
	REX_STORE_U32(ctx.r16.u32 + 128, ctx.r6.u32);
	// lwz r6,120(r1)
	ctx.r6.u64 = REX_LOAD_U32(ctx.r1.u32 + 120);
	// stw r11,264(r16)
	REX_STORE_U32(ctx.r16.u32 + 264, ctx.r11.u32);
	// cmpw cr6,r8,r6
	ctx.cr6.compare<int32_t>(ctx.r8.s32, ctx.r6.s32, ctx.xer);
	// blt cr6,0x8290d6c0
	if (ctx.cr6.lt) goto loc_8290D6C0;
	// lwz r29,112(r1)
	ctx.r29.u64 = REX_LOAD_U32(ctx.r1.u32 + 112);
	// lwz r28,116(r1)
	ctx.r28.u64 = REX_LOAD_U32(ctx.r1.u32 + 116);
loc_8290F50C:
	// lwz r9,84(r1)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r1.u32 + 84);
	// lhz r10,66(r18)
	ctx.r10.u64 = REX_LOAD_U16(ctx.r18.u32 + 66);
	// addi r8,r9,1
	ctx.r8.s64 = ctx.r9.s64 + 1;
	// lhz r7,68(r18)
	ctx.r7.u64 = REX_LOAD_U16(ctx.r18.u32 + 68);
	// rotlwi r9,r10,4
	ctx.r9.u64 = __builtin_rotateleft32(ctx.r10.u32, 4);
	// lhz r11,42(r18)
	ctx.r11.u64 = REX_LOAD_U16(ctx.r18.u32 + 42);
	// rotlwi r10,r7,3
	ctx.r10.u64 = __builtin_rotateleft32(ctx.r7.u32, 3);
	// add r29,r9,r29
	ctx.r29.u64 = ctx.r9.u64 + ctx.r29.u64;
	// lhz r9,268(r16)
	ctx.r9.u64 = REX_LOAD_U16(ctx.r16.u32 + 268);
	// add r28,r10,r28
	ctx.r28.u64 = ctx.r10.u64 + ctx.r28.u64;
	// lwz r10,128(r16)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r16.u32 + 128);
	// addi r9,r9,2
	ctx.r9.s64 = ctx.r9.s64 + 2;
	// stw r8,84(r1)
	REX_STORE_U32(ctx.r1.u32 + 84, ctx.r8.u32);
	// add r11,r11,r10
	ctx.r11.u64 = ctx.r11.u64 + ctx.r10.u64;
	// mr r10,r9
	ctx.r10.u64 = ctx.r9.u64;
	// lwz r9,140(r1)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r1.u32 + 140);
	// stw r29,112(r1)
	REX_STORE_U32(ctx.r1.u32 + 112, ctx.r29.u32);
	// stw r28,116(r1)
	REX_STORE_U32(ctx.r1.u32 + 116, ctx.r28.u32);
	// cmpw cr6,r8,r9
	ctx.cr6.compare<int32_t>(ctx.r8.s32, ctx.r9.s32, ctx.xer);
	// stw r11,128(r16)
	REX_STORE_U32(ctx.r16.u32 + 128, ctx.r11.u32);
	// sth r10,268(r16)
	REX_STORE_U16(ctx.r16.u32 + 268, ctx.r10.u16);
	// bge cr6,0x8290f58c
	if (!ctx.cr6.lt) goto loc_8290F58C;
	// lwz r25,120(r1)
	ctx.r25.u64 = REX_LOAD_U32(ctx.r1.u32 + 120);
	// rotlwi r26,r8,0
	ctx.r26.u64 = __builtin_rotateleft32(ctx.r8.u32, 0);
	// lwz r27,324(r1)
	ctx.r27.u64 = REX_LOAD_U32(ctx.r1.u32 + 324);
	// b 0x8290d5d0
	goto loc_8290D5D0;
loc_8290F574:
	// extsw r3,r11
	ctx.r3.s64 = ctx.r11.s32;
	// addi r1,r1,304
	ctx.r1.s64 = ctx.r1.s64 + 304;
	// b 0x8279e440
	__restgprlr_14(ctx, base);
	return;
loc_8290F580:
	// li r3,4
	ctx.r3.s64 = 4;
	// addi r1,r1,304
	ctx.r1.s64 = ctx.r1.s64 + 304;
	// b 0x8279e440
	__restgprlr_14(ctx, base);
	return;
loc_8290F58C:
	// lwz r9,324(r1)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r1.u32 + 324);
	// li r10,-1
	ctx.r10.s64 = -1;
	// lwz r11,980(r18)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r18.u32 + 980);
	// li r3,0
	ctx.r3.s64 = 0;
	// lwz r9,19436(r9)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r9.u32 + 19436);
	// subf r9,r9,r11
	ctx.r9.u64 = ctx.r11.u64 - ctx.r9.u64;
	// rlwinm r9,r9,30,2,31
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 30) & 0x3FFFFFFF;
	// stw r9,984(r18)
	REX_STORE_U32(ctx.r18.u32 + 984, ctx.r9.u32);
	// stw r10,0(r11)
	REX_STORE_U32(ctx.r11.u32 + 0, ctx.r10.u32);
loc_8290F5B0:
	// addi r1,r1,304
	ctx.r1.s64 = ctx.r1.s64 + 304;
	// b 0x8279e440
	__restgprlr_14(ctx, base);
	return;
}

