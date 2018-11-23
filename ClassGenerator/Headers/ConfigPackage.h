#pragma once

#include <filesystem>
#include <vector>

#include <ConfigFlag.h>

class ConfigPackage
{
    using MemberTypeNamePair = std::pair<std::string, std::string>;
    using MemberTypeNamePairs = std::vector<MemberTypeNamePair>;

private:
    std::string m_ClassName;
    MemberTypeNamePairs m_vMemberTypeNamePairs;
    std::filesystem::path m_OutputPath;

    ConfigFlag m_ConfigMask;

public:
    /// Constructors
    ConfigPackage( );
    ConfigPackage(const ConfigPackage&);
    ConfigPackage(ConfigPackage&&) noexcept;

    /// Destructor
    ~ConfigPackage( );

    /// Assignment Overloads
    ConfigPackage& operator=(const ConfigPackage&);
    ConfigPackage& operator=(ConfigPackage&&) noexcept;

    /// Getters
    const std::string& GetClassName( ) const noexcept;
    const MemberTypeNamePairs& GetMemberPairs( ) const noexcept;
    const std::filesystem::path& GetOutputPath( ) const noexcept;
    const ConfigFlag& GetEnabledOptions( ) const noexcept;

    /// Setters
    void SetClassName(const std::string&);
    void SetClassName(std::string&&) noexcept;
    void SetOutputPath(const std::filesystem::path&);
    void SetOutputPath(std::filesystem::path&&) noexcept;
    void EnableOption(const ConfigFlag&) noexcept;
    void DisableOption(const ConfigFlag&) noexcept;
        
    /// Public Methods
    void AddMemberPair(const std::string& type, const std::string& name);
};
