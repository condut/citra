// Copyright 2014 Citra Emulator Project
// Licensed under GPLv2 or any later version
// Refer to the license.txt file included.

#pragma once

#include <memory>
#include <vector>

#include "common/common_types.h"

#include "core/file_sys/ivfc_archive.h"
#include "core/loader/loader.h"

////////////////////////////////////////////////////////////////////////////////////////////////////
// FileSys namespace

namespace FileSys {

/// File system interface to the RomFS archive
class ArchiveFactory_RomFS final : public ArchiveFactory {
public:
    ArchiveFactory_RomFS(const Loader::AppLoader& app_loader);

    std::string GetName() const override { return "RomFS"; }
    ResultVal<std::unique_ptr<ArchiveBackend>> Open(const Path& path) override;
    ResultCode Format(const Path& path) override;

private:
    std::shared_ptr<FileUtil::IOFile> m_romfs_file;
    u64 m_offset;
    u64 m_size;
};

} // namespace FileSys
