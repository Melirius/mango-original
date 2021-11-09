/*
    MANGO Multimedia Development Platform
    Copyright (C) 2012-2021 Twilight Finland 3D Oy Ltd. All rights reserved.
*/
#include <mango/core/string.hpp>
#include <mango/core/exception.hpp>
#include <mango/filesystem/file.hpp>

namespace mango::filesystem
{

    // -----------------------------------------------------------------
    // File
    // -----------------------------------------------------------------

    File::File(const std::string& s)
    {
        // split s into pathname + filename
        size_t n = s.find_last_of("/\\:");
        std::string filename = s.substr(n + 1);
        std::string filepath = s.substr(0, n + 1);

        m_filename = filename;

        // create a internal path
        m_path = std::make_unique<Path>(filepath);

        Mapper& mapper = m_path->getMapper();

        // memory map the file
        AbstractMapper* abstract_mapper = mapper;
        if (abstract_mapper)
        {
            VirtualMemory* ptr = abstract_mapper->mmap(mapper.basepath() + m_filename);
            if (ptr)
            {
                m_virtual_memory = std::unique_ptr<VirtualMemory>(ptr);
                m_memory = *m_virtual_memory;
            }
        }
    }

    File::File(const Path& path, const std::string& s)
    {
        // split s into pathname + filename
        size_t n = s.find_last_of("/\\:");
        std::string filename = s.substr(n + 1);
        std::string filepath = s.substr(0, n + 1);

        m_filename = filename;

        // create a internal path
        m_path = std::make_unique<Path>(path, filepath);

        Mapper& mapper = m_path->getMapper();

        // memory map the file
        AbstractMapper* abstract_mapper = mapper;
        if (abstract_mapper)
        {
            VirtualMemory* ptr = abstract_mapper->mmap(mapper.basepath() + m_filename);
            if (ptr)
            {
                m_virtual_memory = std::unique_ptr<VirtualMemory>(ptr);
                m_memory = *m_virtual_memory;
            }
        }
    }

    File::File(ConstMemory memory, const std::string& extension, const std::string& filename)
    {
        std::string password;

        // create a internal path
        m_path = std::make_unique<Path>(memory, extension, password);

        Mapper& mapper = m_path->getMapper();

        // parse and create mappers
        std::string temp = filename; // parse modifies the filename; discard the changes
        m_filename = mapper.parse(temp, "");

        // memory map the file
        AbstractMapper* abstract_mapper = mapper;
        if (abstract_mapper)
        {
            VirtualMemory* ptr = abstract_mapper->mmap(m_filename);
            if (ptr)
            {
                m_virtual_memory = std::unique_ptr<VirtualMemory>(ptr);
                m_memory = *m_virtual_memory;
            }
        }
    }

    File::~File()
    {
    }

    const Path& File::path() const
    {
        return *m_path;
    }

    const std::string& File::filename() const
    {
        return m_filename;
    }

    const std::string& File::pathname() const
    {
        return m_path->pathname();
    }

    File::operator ConstMemory () const
    {
        return m_memory;
    }

	File::operator const u8* () const
	{
        return m_memory.address;
	}

    const u8* File::data() const
    {
        return m_memory.address;
    }

    u64 File::size() const
    {
        return m_memory.size;
    }

} // namespace mango::filesystem
