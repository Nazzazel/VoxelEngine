//
// Created by nazzazel on 18.07.2026.
//

#pragma once
namespace engine
{

    enum class Severity : uint8_t {
        Info = 0,     // Just for telemetry/tracking
        Warning,  // Something went wrong, but we have a workaround
        Error,    // A feature failed, need to report
        Fatal     // System must abort (crash or terminate)
    };

    // 0 is always Success.
    enum class ResultCategory : uint8_t {
        // --- General ---
        General = 0,
        System,                //Menager for systems like LoggerSystem,FileSystem
        Platform,             // Core OS/Platform abstraction
        Configuration,      // Config file/Startup settings

        // --- Hardware / Resources ---
        Memory,             // Allocators, OOM errors
        IO,                 // File systems, disk access
        Graphics,           // GPU state, shaders, textures
        Audio,              // Sound drivers, mixing
        Input,              // Keyboard/Mouse/Controller events
        Networking,         // Sockets, synchronization

        // --- Engine Logic ---
        Physics,            // Collisions, dynamics
        Scripting,          // VM states, script binding
        Animation,          // Skeletal, blending, keyframes
        Entity,             // ECS, object lifetime
        Threading,          // Job system, synchronization primitives

        // --- Debug/Support ---
        Profiling,          // Telemetry, instrumentation
        Logging,            // Logger internal errors

        // End of enum (always keep at the end for iletation purposes)
        Count
    };

    struct [[nodiscard]] Result {
        
    private:
        //Init of packed var
        uint64_t m_packed = 0;
        // Private constructor used by the static creator
        explicit constexpr Result(uint64_t packed) noexcept : m_packed(packed) {}

    public:
        // --- Constructors ---
        // Default constructor is Success
        constexpr Result() noexcept : m_packed(0) {}

        static constexpr Result SUCCESS() {return {};};
        // Explicit constructor for creating a result
        static constexpr Result Create(
                //64-bit packet structure //CPU register optimize
                ResultCategory category = ResultCategory::General, //[00-07]     | Size :   8bit -> 0...255     Possible Categories
                uint16_t errorCode = 0,                            //[08-23]     | Size :  16bit -> 0...65 535  Possible Codes
                Severity severity = Severity::Info,                //[24-27]     | Size :  4bit -> 0...15       Possible Severity Levels
                uint64_t payload = 0) noexcept                     //[28-63]     | Size :  36bit -> Additional free space // Currenty used by macros to point the line and filename where the Result was called
        {
            // 1. Mask inputs to ensure they don't overflow their allocated slots
            uint64_t cat_bits = static_cast<uint64_t>(static_cast<uint8_t>(category)) & 0xFF;           // 8 bits
            uint64_t err_bits = (static_cast<uint64_t>(static_cast<uint8_t>(errorCode)) & 0xFFFF) << 8;                       // 16 bits at offset 8
            uint64_t sev_bits = (static_cast<uint64_t>(static_cast<uint8_t>(severity)) & 0xF) << 24;    // 4 bits at offset 24
            uint64_t pay_bits = (payload & 0xFFFFFFFFFULL) << 28;      // 36 bits at offset 28

            return Result(cat_bits | err_bits | sev_bits | pay_bits);
        }

        // Semantic helpers
        [[nodiscard]] constexpr bool IsSuccess() const noexcept { return m_packed == 0; }
        [[nodiscard]] constexpr bool IsFailure() const noexcept { return m_packed != 0; }

        // Optional: Check by category
        [[nodiscard]] constexpr bool IsCategory(ResultCategory cat) const noexcept {
            return getCategory() == cat;
        }

        // --- Accessors ---
         [[nodiscard]] constexpr ResultCategory getCategory()   const noexcept  { return static_cast<ResultCategory>(m_packed & 0xFF); }
         [[nodiscard]] constexpr uint16_t getErrorCode()        const noexcept  { return static_cast<uint16_t>((m_packed >> 8) & 0xFFFF); }
         [[nodiscard]] constexpr Severity getSeverity()         const noexcept  { return static_cast<Severity>((m_packed >> 24) & 0xF); }
         [[nodiscard]] constexpr uint64_t getPayload()          const noexcept  { return (m_packed >> 28); }

    public:
        struct ResultInfo {
            ResultCategory category;
            uint16_t errorCode;
            Severity severity;
            uint64_t payload;
        };

        [[nodiscard]] constexpr ResultInfo Inspect() const noexcept {
            return {
                getCategory(),
                getErrorCode(),
                getSeverity(),
                getPayload()
            };
        }
    };
}