//  Copyright © 2022-2023 ChefKiss Inc. Licensed under the Thou Shalt Not Profit License version 1.5. See LICENSE for
//  details.

#pragma once
#include <Headers/kern_util.hpp>

/**
 * `AppleGraphicsDevicePolicy`
 * Symbols are stripped so function is unknown.
 * Changes frame-buffer count >= 2 check to >= 1.
 */
static const uint8_t kAGDPFBCountCheckOriginal[] = {0x02, 0x00, 0x00, 0x83, 0xF8, 0x02};
static const uint8_t kAGDPFBCountCheckPatched[] = {0x02, 0x00, 0x00, 0x83, 0xF8, 0x01};

/** Ditto */
static const uint8_t kAGDPFBCountCheckVenturaOriginal[] = {0x41, 0x83, 0xBE, 0x14, 0x02, 0x00, 0x00, 0x02};
static const uint8_t kAGDPFBCountCheckVenturaPatched[] = {0x41, 0x83, 0xBE, 0x14, 0x02, 0x00, 0x00, 0x01};

/**
 * `AppleGraphicsDevicePolicy::start`
 * Neutralise access to AGDP configuration by board identifier.
 */
static const uint8_t kAGDPBoardIDKeyOriginal[] = "board-id";
static const uint8_t kAGDPBoardIDKeyPatched[] = "applehax";

/**
 * `_gc_sw_init`
 * AMDRadeonX5000HWLibs.kext
 * Replace call to `_gc_get_hw_version` with constant (0x090400).
 */
static const uint8_t kGcSwInitOriginal[] = {0x0C, 0xE8, 0x00, 0x00, 0x00, 0x00, 0x41, 0x89, 0xC7};
static const uint8_t kGcSwInitOriginalMask[] = {0xFF, 0xFF, 0x00, 0x00, 0x00, 0x00, 0xFF, 0xFF, 0xFF};
static const uint8_t kGcSwInitPatched[] = {0x00, 0xB8, 0x00, 0x04, 0x09, 0x00, 0x00, 0x00, 0x00};
static const uint8_t kGcSwInitPatchedMask[] = {0x00, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0x00, 0x00, 0x00};
static_assert(arrsize(kGcSwInitOriginal) == arrsize(kGcSwInitOriginalMask));
static_assert(arrsize(kGcSwInitOriginal) == arrsize(kGcSwInitPatched));
static_assert(arrsize(kGcSwInitPatched) == arrsize(kGcSwInitPatchedMask));

/**
 * `_gc_set_fw_entry_info`
 * AMDRadeonX5000HWLibs.kext
 * Replace call to `_gc_get_hw_version` with constant (0x090400).
 */
static const uint8_t kGcSetFwEntryInfoOriginal[] = {0xE8, 0x00, 0x00, 0x00, 0x00, 0x31, 0x00, 0x41, 0x89, 0x00, 0x10,
    0x41, 0x89, 0x00, 0x00, 0x00};
static const uint8_t kGcSetFwEntryInfoOriginalMask[] = {0xFF, 0x00, 0x00, 0x00, 0x00, 0xFF, 0x00, 0xFF, 0xFF, 0x00,
    0xFF, 0xFF, 0xFF, 0x00, 0x00, 0x00};
static const uint8_t kGcSetFwEntryInfoPatched[] = {0xB8, 0x00, 0x04, 0x09, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00};
static const uint8_t kGcSetFwEntryInfoPatchedMask[] = {0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00};

/**
 * `_psp_sw_init`
 * AMDRadeonX5000HWLibs.kext
 * Force major version switch case to always use case 0xB.
 */
static const uint8_t kPspSwInitOriginal1[] = {0x8B, 0x43, 0x0C, 0x83, 0xC0, 0xF7, 0x83, 0xF8, 0x04};
static const uint8_t kPspSwInitPatched1[] = {0xC7, 0xC0, 0x02, 0x00, 0x00, 0x00, 0x83, 0xF8, 0x04};

/**
 * `_psp_sw_init`
 * AMDRadeonX5000HWLibs.kext
 * Force minor & patch checks to always use case 0x0.
 */
static const uint8_t kPspSwInitOriginal2[] = {0x8B, 0x43, 0x10, 0x83, 0xF8, 0x05, 0x74, 0x00, 0x85, 0xC0, 0x75, 0x00,
    0x8B, 0x43, 0x14, 0x48, 0x83, 0xF8, 0x0D, 0x77, 0x00};
static const uint8_t kPspSwInitOriginalMask2[] = {0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0x00, 0xFF, 0xFF, 0xFF,
    0x00, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0x00};
static const uint8_t kPspSwInitPatched2[] = {0x66, 0x48, 0x90, 0x66, 0x48, 0x90, 0x48, 0x90, 0x48, 0x90, 0x48, 0x90,
    0x31, 0xC0, 0x90, 0x48, 0x83, 0xF8, 0x0D, 0x00, 0x00};
static const uint8_t kPspSwInitPatchedMask2[] = {0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF,
    0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0x00, 0x00};

/**
 * `_smu_init_function_pointer_list`
 * AMDRadeonX5000HWLibs.kext
 * Replace call to `_smu_get_hw_version` with constant (0x1).
 */
static const uint8_t kSmuInitFunctionPointerListOriginal[] = {0xE8, 0x00, 0x00, 0x00, 0x00, 0x89, 0xC3, 0x41, 0x89,
    0x87, 0x00, 0x00, 0x00, 0x00};
static const uint8_t kSmuInitFunctionPointerListOriginalMask[] = {0xFF, 0x00, 0x00, 0x00, 0x00, 0xFF, 0xFF, 0xFF, 0xFF,
    0xFF, 0x00, 0x00, 0x00, 0x00};
static const uint8_t kSmuInitFunctionPointerListPatched[] = {0xB8, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00};
static const uint8_t kSmuInitFunctionPointerListPatchedMask[] = {0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00};

/**
 * `_smu_9_0_1_full_asic_reset`
 * AMDRadeonX5000HWLibs.kext
 * Change SMC message from `0x3B` to `0x1E` as the original one is wrong for SMU 10/12.
 */
static const uint8_t kFullAsicResetOriginal[] = {0x8B, 0x56, 0x04, 0xBE, 0x3B, 0x00, 0x00, 0x00};
static const uint8_t kFullAsicResetPatched[] = {0x8B, 0x56, 0x04, 0xBE, 0x1E, 0x00, 0x00, 0x00};

/**
 * `AtiApplePowerTuneServices::createPowerTuneServices`
 * AMDRadeonX5000HWLibs.kext
 * Change switch statement case `0x8D` to `0x8E`.
 */
static const uint8_t kCreatePowerTuneServicesOriginal1[] = {0x41, 0x8B, 0x47, 0x18, 0x83, 0xC0, 0x88, 0x83, 0xF8, 0x17};
static const uint8_t kCreatePowerTuneServicesPatched1[] = {0x41, 0x8B, 0x47, 0x18, 0x83, 0xC0, 0x87, 0x83, 0xF8, 0x17};

/** Ditto */
static const uint8_t kCreatePowerTuneServicesMontereyOriginal1[] = {0xB8, 0x7E, 0xFF, 0xFF, 0xFF, 0x41, 0x03, 0x47,
    0x18, 0x83, 0xF8, 0x0F};
static const uint8_t kCreatePowerTuneServicesMontereyPatched1[] = {0xB8, 0x7D, 0xFF, 0xFF, 0xFF, 0x41, 0x03, 0x47, 0x18,
    0x83, 0xF8, 0x0F};

/**
 * `AtiApplePowerTuneServices::createPowerTuneServices`
 * AMDRadeonX5000HWLibs.kext
 * Remove revision check to always use Vega 10 PowerTune.
 */
static const uint8_t kCreatePowerTuneServicesOriginal2[] = {0x41, 0x8B, 0x47, 0x1C, 0x83, 0xF8, 0x13, 0x77, 0x00};
static const uint8_t kCreatePowerTuneServicesMask2[] = {0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0x00};
static const uint8_t kCreatePowerTuneServicesPatched2[] = {0x41, 0x8B, 0x47, 0x1C, 0x66, 0x90, 0x66, 0x90, 0x90};

/**
 * `cailQueryAdapterInfo`
 * AMDRadeonX5000HWLibs.kext
 * Ventura added an explicit switch case for family ID.
 * Now we have to make the switch case 0x8D be 0x8E.
 */
static const uint8_t kCailQueryAdapterInfoOriginal[] = {0x83, 0xC0, 0x92, 0x83, 0xF8, 0x21};
static const uint8_t kCailQueryAdapterInfoPatched[] = {0x83, 0xC0, 0x91, 0x83, 0xF8, 0x21};

/**
 * `_sdma_init_function_pointer_list`
 * AMDRadeonX5000HWLibs.kext
 * Ventura removed the code for SDMA 4.1.x. Force use SDMA 4.0.
 */
static const uint8_t kSDMAInitFunctionPointerListOriginal[] = {0x81, 0xFB, 0x00, 0x00, 0x04, 0x00, 0x0F};
static const uint8_t kSDMAInitFunctionPointerListPatched[] = {0x39, 0xDB, 0x66, 0x90, 0x66, 0x90, 0x0F};

/**
 * `AMDRadeonX6000_AmdAsicInfoNavi::populateDeviceInfo`
 * AMDRadeonX6000Framebuffer.kext
 * Fix register read (0xD31 -> 0xD2F) and family ID (0x8F -> 0x8E).
 */
static const uint8_t kPopulateDeviceInfoOriginal[] {0xBE, 0x31, 0x0D, 0x00, 0x00, 0xFF, 0x90, 0x40, 0x01, 0x00, 0x00,
    0xC7, 0x43, 0x00, 0x8F, 0x00, 0x00, 0x00};
static const uint8_t kPopulateDeviceInfoMask[] {0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF,
    0xFF, 0x00, 0xFF, 0xFF, 0xFF, 0xFF};
static const uint8_t kPopulateDeviceInfoPatched[] {0xBE, 0x2F, 0x0D, 0x00, 0x00, 0xFF, 0x90, 0x40, 0x01, 0x00, 0x00,
    0xC7, 0x43, 0x00, 0x8E, 0x00, 0x00, 0x00};

/**
 * `AmdAtomFwServices::initializeAtomDataTable`
 * AMDRadeonX6000Framebuffer.kext
 * Neutralise `AmdAtomVramInfo` creation null check.
 * We don't have this entry in our VBIOS.
 */
static const uint8_t kAmdAtomVramInfoNullCheckOriginal[] = {0x48, 0x89, 0x83, 0x90, 0x00, 0x00, 0x00, 0x48, 0x85, 0xC0,
    0x0F, 0x84, 0x89, 0x00, 0x00, 0x00, 0x48, 0x8B, 0x7B, 0x18};
static const uint8_t kAmdAtomVramInfoNullCheckPatched[] = {0x48, 0x89, 0x83, 0x90, 0x00, 0x00, 0x00, 0x66, 0x90, 0x66,
    0x90, 0x66, 0x90, 0x66, 0x90, 0x90, 0x48, 0x8B, 0x7B, 0x18};

/** Ditto */
static const uint8_t kAmdAtomVramInfoNullCheckCatalinaOriginal[] = {0x48, 0x89, 0x83, 0x80, 0x00, 0x00, 0x00, 0x48,
    0x85, 0xC0, 0x74, 0x00};
static const uint8_t kAmdAtomVramInfoNullCheckCatalinaMask[] = {0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF,
    0xFF, 0xFF, 0x00};
static const uint8_t kAmdAtomVramInfoNullCheckCatalinaPatched[] = {0x48, 0x89, 0x83, 0x80, 0x00, 0x00, 0x00, 0x66, 0x90,
    0x66, 0x90, 0x90};

/**
 * `AmdAtomFwServices::initializeAtomDataTable`
 * AMDRadeonX6000Framebuffer.kext
 * Neutralise `AmdAtomPspDirectory` creation null check.
 * We don't have this entry in our VBIOS.
 */
static const uint8_t kAmdAtomPspDirectoryNullCheckOriginal[] = {0x48, 0x89, 0x83, 0x88, 0x00, 0x00, 0x00, 0x48, 0x85,
    0xC0, 0x0F, 0x84, 0xA1, 0x00, 0x00, 0x00, 0x48, 0x8B, 0x7B, 0x18};
static const uint8_t kAmdAtomPspDirectoryNullCheckPatched[] = {0x48, 0x89, 0x83, 0x88, 0x00, 0x00, 0x00, 0x66, 0x90,
    0x66, 0x90, 0x66, 0x90, 0x66, 0x90, 0x90, 0x48, 0x8B, 0x7B, 0x18};

/**
 * `AmdAtomFwServices::getFirmwareInfo`
 * AMDRadeonX6000Framebuffer.kext
 * Neutralise `AmdAtomVramInfo` null check.
 */
static const uint8_t kGetFirmwareInfoNullCheckOriginal[] = {0x48, 0x83, 0xBB, 0x00, 0x00, 0x00, 0x00, 0x00, 0x0F, 0x84,
    0x00, 0x00, 0x00, 0x00, 0x49, 0x89};
static const uint8_t kGetFirmwareInfoNullCheckOriginalMask[] = {0xFF, 0xFF, 0xFF, 0x00, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF,
    0xFF, 0x00, 0x00, 0x00, 0x00, 0xFF, 0xFF};
static const uint8_t kGetFirmwareInfoNullCheckPatched[] = {0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x66, 0x90,
    0x66, 0x90, 0x66, 0x90, 0x00, 0x00};
static const uint8_t kGetFirmwareInfoNullCheckPatchedMask[] = {0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xFF,
    0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0x00, 0x00};

/**
 * `AMDRadeonX6000_AmdAgdcServices::getVendorInfo`
 * AMDRadeonX6000Framebuffer.kext
 * Tell AGDC that we're an iGPU.
 */
static const uint8_t kAgdcServicesGetVendorInfoOriginal[] = {0xC7, 0x00, 0x00, 0x00, 0x03, 0x00, 0x48, 0x00, 0x02, 0x10,
    0x00, 0x00, 0x02, 0x00, 0x00, 0x00};
static const uint8_t kAgdcServicesGetVendorInfoMask[] = {0xFF, 0x00, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0x00, 0xFF, 0xFF,
    0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF};
static const uint8_t kAgdcServicesGetVendorInfoPatched[] = {0xC7, 0x00, 0x00, 0x00, 0x03, 0x00, 0x48, 0x00, 0x02, 0x10,
    0x00, 0x00, 0x01, 0x00, 0x00, 0x00};

/**
 * `AMDRadeonX6000_AmdRadeonController::powerUp`
 * AMDRadeonX6000Framebuffer.kext
 * Remove new FB count condition so we can restore the original behaviour before Ventura.
 */
static const uint8_t kControllerPowerUpOriginal[] = {0x38, 0xC8, 0x0F, 0x42, 0xC8, 0x88, 0x8F, 0xBC, 0x00, 0x00, 0x00,
    0x72, 0x00};
static const uint8_t kControllerPowerUpOriginalMask[] = {0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF,
    0xFF, 0xFF, 0x00};
static const uint8_t kControllerPowerUpReplace[] = {0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0xEB, 0x00};
static const uint8_t kControllerPowerUpReplaceMask[] = {0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0xFF, 0x00};

/**
 * `AMDRadeonX6000_AmdRadeonFramebuffer::validateDetailedTiming`
 * AMDRadeonX6000Framebuffer.kext
 * Remove new problematic Ventura pixel clock multiplier calculation which causes timing validation mishaps.
 */
static const uint8_t kValidateDetailedTimingOriginal[] = {0x66, 0x0F, 0x2E, 0xC1, 0x76, 0x06, 0xF2, 0x0F, 0x5E, 0xC1};
static const uint8_t kValidateDetailedTimingPatched[] = {0x66, 0x0F, 0x2E, 0xC1, 0x66, 0x90, 0xF2, 0x0F, 0x5E, 0xC1};

/**
 * `AMDRadeonX5000_AMDHardware::startHWEngines`
 * AMDRadeonX5000.kext
 * Make for loop run only once as we only have one SDMA engine.
 */
static const uint8_t kStartHWEnginesOriginal[] = {0x40, 0x83, 0xF0, 0x02};
static const uint8_t kStartHWEnginesMask[] = {0xF0, 0xFF, 0xF0, 0xFF};
static const uint8_t kStartHWEnginesPatched[] = {0x40, 0x83, 0xF0, 0x01};

/**
 * `Addr::Lib::Create`
 * AMDRadeonX5000.kext
 * The check inside was changed from `familyId - 0x8D < 2` to `familyId == 0x8D` in Ventura 13.4.
 * Change the 0x8D (AI) to 0x8E (RV).
 */
static const uint8_t kAddrLibCreateOriginal[] = {0x41, 0x81, 0x7D, 0x08, 0x8D, 0x00, 0x00, 0x00};
static const uint8_t kAddrLibCreatePatched[] = {0x41, 0x81, 0x7D, 0x08, 0x8E, 0x00, 0x00, 0x00};

/**
 * `AMDRadeonX5000_AMDGraphicsAccelerator::createAccelChannels`
 * AMDRadeonX5000.kext
 * Catalina only. Change loop condition to skip SDMA1_HP.
 */
static const uint8_t kCreateAccelChannelsOriginal[] = {0x8D, 0x44, 0x09, 0x02};
static const uint8_t kCreateAccelChannelsPatched[] = {0x8D, 0x44, 0x09, 0x01};

/**
 * Mismatched `getTtlInterface` virtual calls
 * AMDRadeonX6000.kext
 */
static const uint8_t kGetTtlInterfaceCallOriginal[] = {0x40, 0x80, 0x00, 0xFF, 0x90, 0xC8, 0x02, 0x00, 0x00};
static const uint8_t kGetTtlInterfaceCallOriginalMask[] = {0xF0, 0xF0, 0x00, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF};
static const uint8_t kGetTtlInterfaceCallPatched[] = {0x00, 0x00, 0x00, 0x00, 0x00, 0xC0, 0x00, 0x00, 0x00};
static const uint8_t kGetTtlInterfaceCallPatchedMask[] = {0x00, 0x00, 0x00, 0x00, 0x00, 0xFF, 0x00, 0x00, 0x00};

/**
 * Mismatched `getGpuDebugPolicy` virtual calls.
 * AMDRadeonX6000.kext
 */
static const uint8_t kGetGpuDebugPolicyCallOriginal[] = {0x48, 0x8B, 0x07, 0xFF, 0x90, 0xC0, 0x03, 0x00, 0x00};
static const uint8_t kGetGpuDebugPolicyCallPatched[] = {0x48, 0x8B, 0x07, 0xFF, 0x90, 0xC8, 0x03, 0x00, 0x00};

/** Ditto */
static const uint8_t kGetGpuDebugPolicyCallCatalinaOriginal[] = {0x48, 0x8B, 0x07, 0xFF, 0x90, 0xC8, 0x03, 0x00, 0x00};
static const uint8_t kGetGpuDebugPolicyCallCatalinaPatched[] = {0x48, 0x8B, 0x07, 0xFF, 0x90, 0xC0, 0x03, 0x00, 0x00};

/**
 * `AMDRadeonX6000_AMDHWChannel::submitCommandBuffer`
 * AMDRadeonX6000.kext
 * VTable Call to signalGPUWorkSubmitted.
 * Doesn't exist on X5000, but looks like it isn't necessary, so we just NO-OP it.
 */
static const uint8_t kHWChannelSubmitCommandBufferOriginal[] = {0x48, 0x8B, 0x07, 0xFF, 0x90, 0x30, 0x02, 0x00, 0x00,
    0x48, 0x8B, 0x43};
static const uint8_t kHWChannelSubmitCommandBufferPatched[] = {0x48, 0x8B, 0x07, 0x66, 0x90, 0x66, 0x90, 0x66, 0x90,
    0x48, 0x8B, 0x43};

/** Ditto */
static const uint8_t kHWChannelSubmitCommandBufferCatalinaOriginal[] = {0x48, 0x8B, 0x07, 0xFF, 0x90, 0x20, 0x02, 0x00,
    0x00, 0x49, 0x8B, 0x45};
static const uint8_t kHWChannelSubmitCommandBufferCatalinaPatched[] = {0x48, 0x8B, 0x07, 0x66, 0x90, 0x66, 0x90, 0x66,
    0x90, 0x49, 0x8B, 0x45};

/**
 * Mismatched `getScheduler` virtual calls.
 * AMDRadeonX6000.kext
 */
static const uint8_t kGetSchedulerCallOriginal[] = {0x48, 0x8B, 0x07, 0xFF, 0x90, 0xB8, 0x03, 0x00, 0x00};
static const uint8_t kGetSchedulerCallPatched[] = {0x48, 0x8B, 0x07, 0xFF, 0x90, 0xC0, 0x03, 0x00, 0x00};

/** Ditto */
static const uint8_t kGetSchedulerCallVenturaOriginal[] = {0x48, 0x8B, 0x07, 0xFF, 0x90, 0xB0, 0x03, 0x00, 0x00};
static const uint8_t kGetSchedulerCallVenturaPatched[] = {0x48, 0x8B, 0x07, 0xFF, 0x90, 0xB8, 0x03, 0x00, 0x00};

/** Ditto */
static const uint8_t kGetSchedulerCallCatalinaOriginal[] = {0x48, 0x8B, 0x07, 0xFF, 0x90, 0xC0, 0x03, 0x00, 0x00};
static const uint8_t kGetSchedulerCallCatalinaPatched[] = {0x48, 0x8B, 0x07, 0xFF, 0x90, 0xB8, 0x03, 0x00, 0x00};

/**
 * Mismatched `isDeviceValid` virtual calls.
 * AMDRadeonX6000.kext
 */
static const uint8_t kIsDeviceValidCallOriginal[] = {0x48, 0x8B, 0x07, 0xFF, 0x90, 0xA0, 0x02, 0x00, 0x00};
static const uint8_t kIsDeviceValidCallPatched[] = {0x48, 0x8B, 0x07, 0xFF, 0x90, 0x98, 0x02, 0x00, 0x00};

/**
 * Mismatched `isDevicePCITunnelled` virtual calls.
 * AMDRadeonX6000.kext
 */
static const uint8_t kIsDevicePCITunnelledCallOriginal[] = {0x48, 0x8B, 0x07, 0xFF, 0x90, 0xB0, 0x02, 0x00, 0x00};
static const uint8_t kIsDevicePCITunnelledCallPatched[] = {0x48, 0x8B, 0x07, 0xFF, 0x90, 0xA8, 0x02, 0x00, 0x00};

/**
 * Mismatched `getSML` virtual calls.
 * AMDRadeonX6000.kext
 */
static const uint8_t kGetSMLCallOriginal[] = {0x48, 0x8B, 0x07, 0xFF, 0x90, 0x98, 0x03, 0x00, 0x00};
static const uint8_t kGetSMLCallPatched[] = {0x48, 0x8B, 0x07, 0xFF, 0x90, 0x90, 0x03, 0x00, 0x00};

/**
 * `AMDRadeonX6000_AMDHWDisplay::fillUBMSurface`
 * AMDRadeonX6000.kext
 * Mismatched `getUbmSwizzleMode` virtual call.
 */
static const uint8_t kGetUbmSwizzleModeCallOriginal[] = {0xFF, 0x91, 0x78, 0x04, 0x00, 0x00};
static const uint8_t kGetUbmSwizzleModeCallPatched[] = {0xFF, 0x91, 0xA0, 0x04, 0x00, 0x00};

/**
 * `AMDRadeonX6000_AMDHWDisplay::fillUBMSurface`
 * AMDRadeonX6000.kext
 * Mismatched `getUbmTileMode` virtual call.
 */
static const uint8_t kGetUbmTileModeCallOriginal[] = {0xFF, 0x90, 0x80, 0x04, 0x00, 0x00};
static const uint8_t kGetUbmTileModeCallPatched[] = {0xFF, 0x90, 0xA8, 0x04, 0x00, 0x00};

/**
 * `AMDRadeonX6000_AMDHWDisplay::writeUpdateFrameBufferOffsetCommands`
 * AMDRadeonX6000.kext
 * Mismatched `writeWaitForRenderingPipe` virtual call.
 */
static const uint8_t kWriteWaitForRenderingPipeCallOriginal[] = {0xFF, 0x90, 0xB8, 0x02, 0x00, 0x00, 0x89, 0x45, 0xAC};
static const uint8_t kWriteWaitForRenderingPipeCallPatched[] = {0xFF, 0x90, 0xB0, 0x02, 0x00, 0x00, 0x89, 0x45, 0xAC};

/**
 * `AMDRadeonX6000_AMDRTRing::WPTRDiagnostic`
 * AMDRadeonX6000.kext
 * Mismatched `dummyWPTRUpdateDiag` virtual call.
 */
static const uint8_t kDummyWPTRUpdateDiagCallOriginal[] = {0x48, 0x8B, 0x80, 0x50, 0x02, 0x00, 0x00};
static const uint8_t kDummyWPTRUpdateDiagCallPatched[] = {0x48, 0x8B, 0x80, 0x48, 0x02, 0x00, 0x00};

/**
 * `AMDRadeonX6000_AMDHWDisplay::init`
 * AMDRadeonX6000.kext
 * Mismatched `getPM4CommandsUtility` virtual call.
 */
static const uint8_t kGetPM4CommandUtilityCallOriginal[] = {0xFF, 0x90, 0xA0, 0x03, 0x00, 0x00};
static const uint8_t kGetPM4CommandUtilityCallPatched[] = {0xFF, 0x90, 0x98, 0x03, 0x00, 0x00};

/**
 * `AMDRadeonX6000_AMDRTRing::allocateMemoryResources`
 * AMDRadeonX6000.kext
 * Mismatched `getChannelDoorbellOffset` virtual call.
 */
static const uint8_t kGetChannelDoorbellOffsetCallOriginal[] = {0x48, 0x8B, 0x07, 0xFF, 0x90, 0x88, 0x03, 0x00, 0x00};
static const uint8_t kGetChannelDoorbellOffsetCallPatched[] = {0x48, 0x8B, 0x07, 0xFF, 0x90, 0x80, 0x03, 0x00, 0x00};

/**
 * `AMDRadeonX6000_AMDRTRing::allocateMemoryResources`
 * AMDRadeonX6000.kext
 * Mismatched `getDoorbellMemoryBaseAddress` virtual call.
 */
static const uint8_t kGetDoorbellMemoryBaseAddressCallOriginal[] = {0xFF, 0x90, 0x80, 0x03, 0x00, 0x00};
static const uint8_t kGetDoorbellMemoryBaseAddressCallPatched[] = {0xFF, 0x90, 0x78, 0x03, 0x00, 0x00};

/**
 * Mismatched `updateUtilizationStatisticsCounter` virtual calls.
 * AMDRadeonX6000.kext
 */
static const uint8_t kUpdateUtilizationStatisticsCounterCallOriginal[] = {0x41, 0xFF, 0x90, 0xE0, 0x03, 0x00, 0x00};
static const uint8_t kUpdateUtilizationStatisticsCounterCallPatched[] = {0x41, 0xFF, 0x90, 0xD8, 0x03, 0x00, 0x00};

/**
 * `AMDRadeonX6000_AMDHWChannel::submitCommandBuffer`
 * AMDRadeonX6000.kext
 * Mismatched `dumpASICHangState` virtual calls.
 */
static const uint8_t kDumpASICHangStateCallOriginal[] = {0xFF, 0x90, 0xA8, 0x03, 0x00, 0x00};
static const uint8_t kDumpASICHangStateCallPatched[] = {0xFF, 0x90, 0xA0, 0x03, 0x00, 0x00};

/**
 * `AMDRadeonX6000_AMDHWChannel::init`
 * AMDRadeonX6000.kext
 * Mismatched `registerChannel` virtual call.
 */
static const uint8_t kRegisterChannelCallOriginal[] = {0x4C, 0x89, 0xEE, 0xFF, 0x90, 0x28, 0x03, 0x00, 0x00};
static const uint8_t kRegisterChannelCallPatched[] = {0x4C, 0x89, 0xEE, 0xFF, 0x90, 0x20, 0x03, 0x00, 0x00};

/**
 * Mismatched `disableGfxOff` virtual calls.
 * AMDRadeonX6000.kext
 */
static const uint8_t kDisableGfxOffCallOriginal[] = {0xFF, 0x90, 0x00, 0x04, 0x00, 0x00};
static const uint8_t kDisableGfxOffCallPatched[] = {0xFF, 0x90, 0xF8, 0x03, 0x00, 0x00};

/**
 * Mismatched `enableGfxOff` virtual calls.
 * AMDRadeonX6000.kext
 */
static const uint8_t kEnableGfxOffCallOriginal[] = {0xFF, 0x90, 0x08, 0x04, 0x00, 0x00};
static const uint8_t kEnableGfxOffCallPatched[] = {0xFF, 0x90, 0x00, 0x04, 0x00, 0x00};

/**
 * Mismatched `getHWMemory` virtual calls.
 * AMDRadeonX6000.kext
 */
static const uint8_t kGetHWMemoryCallOriginal[] = {0x18, 0x48, 0x8B, 0x07, 0xFF, 0x90, 0xE0, 0x02, 0x00, 0x00, 0x48};
static const uint8_t kGetHWMemoryCallPatched[] = {0x18, 0x48, 0x8B, 0x07, 0xFF, 0x90, 0xD8, 0x02, 0x00, 0x00, 0x48};

/**
 * Mismatched `getHWGart` virtual calls.
 * AMDRadeonX6000.kext
 */
static const uint8_t kGetHWGartCallOriginal[] = {0x48, 0x8B, 0x07, 0xFF, 0x90, 0xE8, 0x02, 0x00, 0x00};
static const uint8_t kGetHWGartCallPatched[] = {0x48, 0x8B, 0x07, 0xFF, 0x90, 0xE0, 0x02, 0x00, 0x00};

/**
 * Mismatched `getChannelCount` virtual calls.
 * AMDRadeonX6000.kext
 */
static const uint8_t kGetChannelCountCallOriginal[] = {0x48, 0x8B, 0x07, 0xFF, 0x90, 0x38, 0x03, 0x00, 0x00};
static const uint8_t kGetChannelCountCallPatched[] = {0x48, 0x8B, 0x07, 0xFF, 0x90, 0x30, 0x03, 0x00, 0x00};

/**
 * Mismatched `flushSystemCaches` virtual calls.
 * AMDRadeonX6000.kext
 */
static const uint8_t kFlushSystemCachesCallOriginal[] = {0xFF, 0x90, 0xA8, 0x04, 0x00, 0x00};
static const uint8_t kFlushSystemCachesCallPatched[] = {0xFF, 0x90, 0xD0, 0x04, 0x00, 0x00};

/**
 * Mismatched `getIOPCIDevice` virtual calls.
 * AMDRadeonX6000.kext
 */
static const uint8_t kGetIOPCIDeviceCallOriginal[] = {0xFF, 0x90, 0x90, 0x03, 0x00, 0x00};
static const uint8_t kGetIOPCIDeviceCallPatched[] = {0xFF, 0x90, 0x88, 0x03, 0x00, 0x00};

/**
 * Mismatched `getHWRegisters` virtual calls.
 * AMDRadeonX6000.kext
 */
static const uint8_t kGetHWRegistersCallOriginal[] = {0x40, 0x80, 0x00, 0xFF, 0x90, 0xD8, 0x02, 0x00, 0x00};
static const uint8_t kGetHWRegistersCallOriginalMask[] = {0xF0, 0xF0, 0x00, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF};
static const uint8_t kGetHWRegistersCallPatched[] = {0x00, 0x00, 0x00, 0x00, 0x00, 0xD0, 0x00, 0x00, 0x00};
static const uint8_t kGetHWRegistersCallPatchedMask[] = {0x00, 0x00, 0x00, 0x00, 0x00, 0xFF, 0x00, 0x00, 0x00};

/**
 * Mismatched `getChannelWriteBackFrameAddr` virtual calls.
 * AMDRadeonX6000.kext
 */
static const uint8_t kGetChannelWriteBackFrameAddrCallOriginal[] = {0xFF, 0x90, 0x50, 0x03, 0x00, 0x00, 0x40};
static const uint8_t kGetChannelWriteBackFrameAddrCallOriginalMask[] = {0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xF0};
static const uint8_t kGetChannelWriteBackFrameAddrCallPatched[] = {0x00, 0x00, 0x48, 0x00, 0x00, 0x00, 0x00};
static const uint8_t kGetChannelWriteBackFrameAddrCallPatchedMask[] = {0x00, 0x00, 0xFF, 0x00, 0x00, 0x00, 0x00};

/**
 * Mismatched `getChannelWriteBackFrameOffset` virtual calls.
 * AMDRadeonX6000.kext
 */
static const uint8_t kGetChannelWriteBackFrameOffsetCall1Original[] = {0x48, 0x8B, 0x07, 0xFF, 0x90, 0x48, 0x03, 0x00,
    0x00};
static const uint8_t kGetChannelWriteBackFrameOffsetCall1Patched[] = {0x48, 0x8B, 0x07, 0xFF, 0x90, 0x40, 0x03, 0x00,
    0x00};

static const uint8_t kGetChannelWriteBackFrameOffsetCall2Original[] = {0x89, 0xDE, 0xFF, 0x90, 0x48, 0x03, 0x00, 0x00};
static const uint8_t kGetChannelWriteBackFrameOffsetCall2Patched[] = {0x89, 0xDE, 0xFF, 0x90, 0x40, 0x03, 0x00, 0x00};

/**
 * Mismatched `getHWChannel` virtual calls.
 * AMDRadeonX6000.kext
 */
static const uint8_t kGetHWChannelCall1Original[] = {0x48, 0x8B, 0x07, 0xFF, 0x90, 0x20, 0x03, 0x00, 0x00, 0x48, 0x85,
    0xC0};
static const uint8_t kGetHWChannelCall1Patched[] = {0x48, 0x8B, 0x07, 0xFF, 0x90, 0x18, 0x03, 0x00, 0x00, 0x48, 0x85,
    0xC0};

static const uint8_t kGetHWChannelCall2Original[] = {0x31, 0xD2, 0xFF, 0x90, 0x18, 0x03, 0x00, 0x00};
static const uint8_t kGetHWChannelCall2Patched[] = {0x31, 0xD2, 0xFF, 0x90, 0x10, 0x03, 0x00, 0x00};

static const uint8_t kGetHWChannelCall3Original[] = {0x00, 0x00, 0x00, 0xFF, 0x90, 0x18, 0x03, 0x00, 0x00};
static const uint8_t kGetHWChannelCall3Patched[] = {0x00, 0x00, 0x00, 0xFF, 0x90, 0x10, 0x03, 0x00, 0x00};

/**
 * Mismatched `getHWAlignManager` virtual calls.
 * AMDRadeonX6000.kext
 */
static const uint8_t kGetHWAlignManagerCall1Original[] = {0x48, 0x80, 0x00, 0xFF, 0x90, 0x00, 0x03, 0x00, 0x00};
static const uint8_t kGetHWAlignManagerCall1OriginalMask[] = {0xFF, 0xF0, 0x00, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF};
static const uint8_t kGetHWAlignManagerCall1Patched[] = {0x00, 0x00, 0x00, 0x00, 0x00, 0xF8, 0x02, 0x00, 0x00};
static const uint8_t kGetHWAlignManagerCall1PatchedMask[] = {0x00, 0x00, 0x00, 0x00, 0x00, 0xFF, 0xFF, 0x00, 0x00};

static const uint8_t kGetHWAlignManagerCall2Original[] = {0x49, 0x89, 0xD4, 0xFF, 0x90, 0x00, 0x03, 0x00, 0x00};
static const uint8_t kGetHWAlignManagerCall2Patched[] = {0x49, 0x89, 0xD4, 0xFF, 0x90, 0xF8, 0x02, 0x00, 0x00};

/**
 * Mismatched `getHWEngine` virtual calls.
 * AMDRadeonX6000.kext
 */
static const uint8_t kGetHWEngineCallOriginal[] = {0x00, 0x00, 0x00, 0xFF, 0x90, 0x10, 0x03, 0x00, 0x00};
static const uint8_t kGetHWEngineCallPatched[] = {0x00, 0x00, 0x00, 0xFF, 0x90, 0x08, 0x03, 0x00, 0x00};

/**
 * Mismatched `getAMDHWHandler` virtual calls.
 * AMDRadeonX6000.kext
 */
static const uint8_t kGetAMDHWHandlerCallOriginal[] = {0xFF, 0x90, 0xD0, 0x02, 0x00, 0x00};
static const uint8_t kGetAMDHWHandlerCallPatched[] = {0xFF, 0x90, 0xC8, 0x02, 0x00, 0x00};

/**
 * `AppleGFXHDAFunctionGroupFactory::createAppleHDAFunctionGroup`
 * AppleGFXHDA.kext
 */
static const uint8_t kCreateAppleHDAFunctionGroup1Original[] = {0x3D, 0xD7, 0xAA, 0x00, 0x00};
static const uint8_t kCreateAppleHDAFunctionGroup1Patched[] = {0x3D, 0x00, 0x00, 0x00, 0x00};
static_assert(arrsize(kCreateAppleHDAFunctionGroup1Original) == arrsize(kCreateAppleHDAFunctionGroup1Patched));

/**
 * `AppleGFXHDAFunctionGroupFactory::createAppleHDAFunctionGroup`
 * AppleGFXHDA.kext
 */
static const uint8_t kCreateAppleHDAFunctionGroup2Original[] = {0x3D, 0xF7, 0xAA, 0x00, 0x00, 0x7F};
static const uint8_t kCreateAppleHDAFunctionGroup2Patched[] = {0x3D, 0xF7, 0xAA, 0x00, 0x00, 0xEB};
static_assert(arrsize(kCreateAppleHDAFunctionGroup2Original) == arrsize(kCreateAppleHDAFunctionGroup2Patched));

/**
 * `AppleGFXHDAWidgetFactory::createAppleHDAWidget`
 * AppleGFXHDA.kext
 * Force else path for `deviceID < 0xAA88` and `deviceID < 0xAAE0` check
 */
static const uint8_t kCreateAppleHDAWidget1Original[] = {0x3D, 0x87, 0xAA, 0x00, 0x00, 0x7E, 0x00, 0x3D, 0xDF, 0xAA,
    0x00, 0x00, 0x7F, 0x00};
static const uint8_t kCreateAppleHDAWidget1OriginalMask[] = {0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0x00, 0xFF, 0xFF, 0xFF,
    0xFF, 0xFF, 0xFF, 0x00};
static const uint8_t kCreateAppleHDAWidget1Patched[] = {0x66, 0x90, 0x66, 0x90, 0x66, 0x90, 0x90, 0x66, 0x90, 0x66,
    0x90, 0x90, 0xEB, 0x00};
static const uint8_t kCreateAppleHDAWidget1PatchedMask[] = {0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF,
    0xFF, 0xFF, 0xFF, 0x00};
static_assert(arrsize(kCreateAppleHDAWidget1Original) == arrsize(kCreateAppleHDAWidget1OriginalMask));
static_assert(arrsize(kCreateAppleHDAWidget1Patched) == arrsize(kCreateAppleHDAWidget1PatchedMask));
static_assert(arrsize(kCreateAppleHDAWidget1Original) == arrsize(kCreateAppleHDAWidget1Patched));

/**
 * `AppleGFXHDAWidgetFactory::createAppleHDAWidget`
 * AppleGFXHDA.kext
 * Force else path for `deviceID < 0xAB20` check
 */
static const uint8_t kCreateAppleHDAWidget2Original[] = {0x3D, 0x1F, 0xAB, 0x00, 0x00, 0x7E, 0x00};
static const uint8_t kCreateAppleHDAWidget2OriginalMask[] = {0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0x00};
static const uint8_t kCreateAppleHDAWidget2Patched[] = {0x66, 0x90, 0x66, 0x90, 0x66, 0x90, 0x90};
static_assert(arrsize(kCreateAppleHDAWidget2Original) == arrsize(kCreateAppleHDAWidget2OriginalMask));
static_assert(arrsize(kCreateAppleHDAWidget2Original) == arrsize(kCreateAppleHDAWidget2Patched));

/**
 * `AppleGFXHDAWidgetFactory::createAppleHDAWidget`
 * `AppleGFXHDAFunctionGroupFactory::createAppleHDAFunctionGroup`
 * AppleGFXHDA.kext
 * Force else path for `0x18 < deviceID - 0xAB20` check
 */
static const uint8_t kCreateAppleHDAOriginal[] = {0x8D, 0x88, 0xE0, 0x54, 0xFF, 0xFF, 0x83, 0xF9, 0x18, 0x77, 0x00};
static const uint8_t kCreateAppleHDAOriginalMask[] = {0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0x00};
static const uint8_t kCreateAppleHDAPatched[] = {0x66, 0x90, 0x66, 0x90, 0x66, 0x90, 0x66, 0x90, 0x90, 0xEB, 0x00};
static const uint8_t kCreateAppleHDAPatchedMask[] = {0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0x00};
static_assert(arrsize(kCreateAppleHDAOriginal) == arrsize(kCreateAppleHDAOriginalMask));
static_assert(arrsize(kCreateAppleHDAPatched) == arrsize(kCreateAppleHDAPatchedMask));
static_assert(arrsize(kCreateAppleHDAOriginal) == arrsize(kCreateAppleHDAPatched));

/**
 * `AppleGFXHDAWidgetFactory::createAppleHDAWidget`
 * `AppleGFXHDAFunctionGroupFactory::createAppleHDAFunctionGroup`
 * AppleGFXHDA.kext
 * Force `deviceID == 0xA*F8` path
 */
static const uint8_t kCreateAppleHDA2Original[] = {0x3D, 0xF8, 0xA0, 0x00, 0x00, 0x74, 0x00};
static const uint8_t kCreateAppleHDA2OriginalMask[] = {0xFF, 0xFF, 0xF0, 0xFF, 0xFF, 0xFF, 0x00};
static const uint8_t kCreateAppleHDA2Patched[] = {0x66, 0x90, 0x66, 0x90, 0x90, 0xEB, 0x00};
static const uint8_t kCreateAppleHDA2PatchedMask[] = {0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0x00};
static_assert(arrsize(kCreateAppleHDA2Original) == arrsize(kCreateAppleHDA2OriginalMask));
static_assert(arrsize(kCreateAppleHDA2Patched) == arrsize(kCreateAppleHDA2PatchedMask));
static_assert(arrsize(kCreateAppleHDA2Original) == arrsize(kCreateAppleHDA2Patched));

/**
 * `AppleHDAFunctionGroupFactory::createAppleHDAFunctionGroup`
 * `AppleHDAWidgetFactory::createAppleHDAWidget`
 * AppleHDA.kext
 */
static const uint8_t kAHDACreate1Original[] = {0x87, 0xAA, 0x00, 0x00, 0x0F, 0x8F};
static const uint8_t kAHDACreate1Patched[] = {0x66, 0x90, 0x66, 0x90, 0x48, 0xE9};
static_assert(arrsize(kAHDACreate1Original) == arrsize(kAHDACreate1Patched));

/**
 * `AppleHDAFunctionGroupFactory::createAppleHDAFunctionGroup`
 * `AppleHDAWidgetFactory::createAppleHDAWidget`
 * AppleHDA.kext
 */
static const uint8_t kAHDACreate2Original[] = {0x83, 0x00, 0x38, 0x77, 0x00, 0xB0};
static const uint8_t kAHDACreate2OriginalMask[] = {0xFF, 0x00, 0xFF, 0xFF, 0x00, 0xF0};
static const uint8_t kAHDACreate2Patched[] = {0x66, 0x90, 0x90, 0xEB, 0x00, 0x00};
static const uint8_t kAHDACreate2PatchedMask[] = {0xFF, 0xFF, 0xFF, 0xFF, 0x00, 0x00};
static_assert(arrsize(kAHDACreate2Original) == arrsize(kAHDACreate2Patched));

/**
 * `AppleHDAFunctionGroupFactory::createAppleHDAFunctionGroup`
 * `AppleHDAWidgetFactory::createAppleHDAWidget`
 * AppleHDA.kext
 */
static const uint8_t kAHDACreate3Original[] = {0xD8, 0xAA, 0x00, 0x00, 0x75, 0x00};
static const uint8_t kAHDACreate3Mask[] = {0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0x00};
static const uint8_t kAHDACreate3Patched[] = {0x66, 0x90, 0x66, 0x90, 0x66, 0x90};
static_assert(arrsize(kAHDACreate3Original) == arrsize(kAHDACreate3Mask));
static_assert(arrsize(kAHDACreate3Original) == arrsize(kAHDACreate3Patched));