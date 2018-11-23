#include <ConfigPackage.h>


// Default Constructor
ConfigPackage::ConfigPackage( ) :
    m_ConfigMask(ConfigFlag::NONE)
{ }

// Copy Constructor
ConfigPackage::ConfigPackage(const ConfigPackage& src) :
    ConfigPackage( )
{
    *this = src;
}

// Move Constructor
ConfigPackage::ConfigPackage(ConfigPackage&& src) noexcept :
    ConfigPackage( )
{
    *this = std::move(src);
}

// Destructor (default)
ConfigPackage::~ConfigPackage( ) = default;

// Copy Assignment
ConfigPackage& ConfigPackage::operator=(const ConfigPackage& src)
{
    if ( this != &src )
    {
        m_ClassName = src.m_ClassName;
        m_vMemberTypeNamePairs = src.m_vMemberTypeNamePairs;
        m_OutputPath = src.m_OutputPath;

        m_ConfigMask = src.m_ConfigMask;
    }

    return *this;
}

// Move Assignment
ConfigPackage& ConfigPackage::operator=(ConfigPackage&& src) noexcept
{
    if ( this != &src )
    {
        m_ClassName = std::move(src.m_ClassName);
        m_vMemberTypeNamePairs = std::move(src.m_vMemberTypeNamePairs);
        m_OutputPath = std::move(src.m_OutputPath);

        m_ConfigMask = src.m_ConfigMask;
    }

    return *this;
}

/// Getters \\\

const std::string& ConfigPackage::GetClassName( ) const noexcept
{
    return m_ClassName;
}

const ConfigPackage::MemberTypeNamePairs& ConfigPackage::GetMemberPairs( ) const noexcept
{
    return m_vMemberTypeNamePairs;
}

const std::filesystem::path& ConfigPackage::GetOutputPath( ) const noexcept
{
    return m_OutputPath;
}

const ConfigFlag& ConfigPackage::GetEnabledOptions( ) const noexcept
{
    return m_ConfigMask;
}

/// Setters \\\

void ConfigPackage::SetClassName(const std::string& name)
{
    m_ClassName = name;
}

void ConfigPackage::SetClassName(std::string&& name) noexcept
{
    m_ClassName = std::move(name);
}

void ConfigPackage::SetOutputPath(const std::filesystem::path& path)
{
    m_OutputPath = path;
}

void ConfigPackage::SetOutputPath(std::filesystem::path&& path) noexcept
{
    m_OutputPath = std::move(path);
}

void ConfigPackage::EnableOption(const ConfigFlag& flag) noexcept
{
    m_ConfigMask |= flag;
}

void ConfigPackage::DisableOption(const ConfigFlag& flag) noexcept
{
    m_ConfigMask &= ~(flag);
}

/// Public Methods \\\

void ConfigPackage::AddMemberPair(const std::string& type, const std::string& name)
{
    m_vMemberTypeNamePairs.emplace_back(type, name);
}
