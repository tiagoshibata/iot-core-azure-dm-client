#include "stdafx.h"
#include <windows.h>
#include "LocalMachine.h"
#include "CSPs\MdmProvision.h"
#include "CSPs\RebootCSP.h"
#include "CSPs\UpdateCSP.h"
#include "CSPs\PolicyCSP.h"

using namespace std;

void LocalMachine::Reboot()
{
    TRACE("LocalMachine::OnDeviceRebootExecute()");
    RebootCSP::ExecRebootNow();
    return;
}

unsigned int LocalMachine::GetTotalMemoryMB()
{
    TRACE("LocalMachine::GetTotalMemoryMB()");

    MEMORYSTATUSEX statex;
    statex.dwLength = sizeof(statex);
    GlobalMemoryStatusEx(&statex);
    return static_cast<unsigned int>(statex.ullTotalPhys) / (1024 * 1024);
}

unsigned int LocalMachine::GetAvailableMemoryMB()
{
    TRACE("LocalMachine::GetAvailableMemoryKB()");

    MEMORYSTATUSEX statex;
    statex.dwLength = sizeof(statex);
    GlobalMemoryStatusEx(&statex);
    return static_cast<unsigned int>(statex.ullAvailPhys) / (1024 * 1024);
}

unsigned int LocalMachine::GetBatteryLevel()
{
    // ToDo: NotImpl
    TRACE("LocalMachine::GetBatteryLevel()");

    static unsigned int level = 100;
    if (level >= 10)
    {
        level -= 10;
    }
    else
    {
        level = 100;
    }
    return level;
}

unsigned int LocalMachine::GetBatteryStatus()
{
    // ToDo: NotImpl
    TRACE("LocalMachine::GetBatteryStatus()");
    return 2;
}

void LocalMachine::RunSyncML(const wstring& request, wstring& response)
{
    wstring sid = L""; // only supports device-wide operations for now.
    MdmProvision::RunSyncML(sid, request, response);
}

void LocalMachine::RunSyncMLAdd(const wstring& path, const wstring& value)
{
    wstring sid = L""; // only supports device-wide operations for now.
    MdmProvision::RunAdd(sid, path, value);
}

wstring LocalMachine::RunSyncMLGetString(const wstring& path)
{
    wstring sid = L""; // only supports device-wide operations for now.
    return MdmProvision::RunGetString(sid, path);
}

unsigned int LocalMachine::RunSyncMLGetInt(const wstring& path)
{
    wstring sid = L""; // only supports device-wide operations for now.
    return MdmProvision::RunGetUInt(sid, path);
}

void LocalMachine::RunSyncMLSet(const wstring& path, const wstring& value)
{
    wstring sid = L""; // only supports device-wide operations for now.
    MdmProvision::RunSet(sid, path, value);
}

void LocalMachine::RunSyncMLSet(const wstring& path, unsigned int value)
{
    wstring sid = L""; // only supports device-wide operations for now.
    MdmProvision::RunSet(sid, path, value);
}

void LocalMachine::GetInstalledUpdates(vector<wstring>& guids)
{
    UpdateCSP::GetInstalledUpdates(guids);
}

void LocalMachine::GetApprovedUpdates(vector<wstring>& guids)
{
    UpdateCSP::GetInstalledUpdates(guids);
}

void LocalMachine::AddApprovedUpdates(const wstring& guid)
{
    UpdateCSP::AddApprovedUpdates(guid);
}

void LocalMachine::GetFailedUpdates(vector<wstring>& guids)
{
    UpdateCSP::GetFailedUpdates(guids);
}

void LocalMachine::GetInstallableUpdates(vector<wstring>& guids)
{
    UpdateCSP::GetInstallableUpdates(guids);
}

void LocalMachine::GetPendingRebootUpdates(vector<wstring>& guids)
{
    UpdateCSP::GetPendingRebootUpdates(guids);
}

wstring LocalMachine::GetLastSuccessfulScanTime()
{
    return UpdateCSP::GetLastSuccessfulScanTime();
}

bool LocalMachine::GetDeferUpgrade()
{
    return UpdateCSP::GetDeferUpgrade();
}

unsigned int LocalMachine::GetActiveHoursStart()
{
    return PolicyCSP::GetActiveHoursStart();
}

void LocalMachine::SetActiveHoursStart(unsigned int hours)
{
    PolicyCSP::SetActiveHoursStart(hours);
}

unsigned int LocalMachine::GetActiveHoursEnd()
{
    return PolicyCSP::GetActiveHoursEnd();
}

void LocalMachine::SetActiveHoursEnd(unsigned int hours)
{
    PolicyCSP::SetActiveHoursEnd(hours);
}

unsigned int LocalMachine::GetAllowAutoUpdate()
{
    return PolicyCSP::GetAllowAutoUpdate();
}

void LocalMachine::SetAllowAutoUpdate(unsigned int allowLevel)
{
    PolicyCSP::SetAllowAutoUpdate(allowLevel);
}

unsigned int LocalMachine::GetAllowMUUpdateService()
{
    return PolicyCSP::GetAllowMUUpdateService();
}

void LocalMachine::SetAllowMUUpdateService(unsigned int allowLevel)
{
    PolicyCSP::SetAllowMUUpdateService(allowLevel);
}

unsigned int LocalMachine::GetAllowNonMicrosoftSignedUpdate()
{
    return PolicyCSP::GetAllowNonMicrosoftSignedUpdate();
}

void LocalMachine::SetAllowNonMicrosoftSignedUpdate(unsigned int allowLevel)
{
    PolicyCSP::SetAllowNonMicrosoftSignedUpdate(allowLevel);
}

unsigned int LocalMachine::GetAllowUpdateService()
{
    return PolicyCSP::GetAllowUpdateService();
}

void LocalMachine::SetAllowUpdateService(unsigned int allowLevel)
{
    PolicyCSP::SetAllowUpdateService(allowLevel);
}

unsigned int LocalMachine::GetBranchReadinessLevel()
{
    return PolicyCSP::GetBranchReadinessLevel();
}

void LocalMachine::SetBranchReadinessLevel(unsigned int level)
{
    PolicyCSP::SetBranchReadinessLevel(level);
}

unsigned int LocalMachine::GetDeferFeatureUpdatesPeriodInDays()
{
    return PolicyCSP::GetDeferFeatureUpdatesPeriodInDays();
}

void LocalMachine::SetDeferFeatureUpdatesPeriodInDays(unsigned int days)
{
    PolicyCSP::SetDeferFeatureUpdatesPeriodInDays(days);
}

unsigned int LocalMachine::GetDeferQualityUpdatesPeriodInDays()
{
    return PolicyCSP::GetDeferQualityUpdatesPeriodInDays();
}

void LocalMachine::SetDeferQualityUpdatesPeriodInDays(unsigned int days)
{
    PolicyCSP::SetDeferQualityUpdatesPeriodInDays(days);
}

unsigned int LocalMachine::GetExcludeWUDrivers()
{
    return PolicyCSP::GetExcludeWUDrivers();
}

void LocalMachine::SetExcludeWUDrivers(unsigned int excludeLevel)
{
    PolicyCSP::SetExcludeWUDrivers(excludeLevel);
}

unsigned int LocalMachine::GetPauseFeatureUpdates()
{
    return PolicyCSP::GetPauseFeatureUpdates();
}

void LocalMachine::SetPauseFeatureUpdates(unsigned int pauseLevel)
{
    PolicyCSP::SetPauseFeatureUpdates(pauseLevel);
}

unsigned int LocalMachine::GetPauseQualityUpdates()
{
    return PolicyCSP::GetPauseQualityUpdates();
}

void LocalMachine::SetPauseQualityUpdates(unsigned int pauseLevel)
{
    PolicyCSP::SetPauseQualityUpdates(pauseLevel);
}

unsigned int LocalMachine::GetRequireUpdateApproval()
{
    return PolicyCSP::GetRequireUpdateApproval();
}

void LocalMachine::SetRequireUpdateApproval(unsigned int value)
{
    PolicyCSP::SetRequireUpdateApproval(value);
}

unsigned int LocalMachine::GetScheduledInstallDay()
{
    return PolicyCSP::GetScheduledInstallDay();
}

void LocalMachine::SetScheduledInstallDay(unsigned int dayOfWeek)
{
    PolicyCSP::SetScheduledInstallDay(dayOfWeek);
}

unsigned int LocalMachine::GetScheduledInstallTime()
{
    return PolicyCSP::GetScheduledInstallTime();
}

void LocalMachine::SetScheduledInstallTime(unsigned int hour)
{
    PolicyCSP::SetScheduledInstallTime(hour);
}

wstring LocalMachine::GetUpdateServiceUrl()
{
    return PolicyCSP::GetUpdateServiceUrl();
}

void LocalMachine::SetUpdateServiceUrl(const std::wstring& serviceUrl)
{
    PolicyCSP::SetUpdateServiceUrl(serviceUrl);
}
