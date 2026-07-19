// //
// // Created by nazzazel on 18.07.2026.
// //
//
// #pragma once
// #include <cstdint>
//
// namespace engine
// {
//     struct Result
//     {
//         uint32_t m_category;
//         uint32_t m_code;
//
//         inline Result(int32_t category, int32_t code) : m_category(category), m_code(code){};
//
//         [[nodiscard]] inline bool Success() const noexcept { return m_code == 0; };
//     };
// }
// /*
// * #pragma once
// #include <cstdint>
//
// namespace engine
// {
//     // Using an underlying type of uint8_t keeps the enum size explicit
//     enum class Category : uint8_t {
//         General = 0,
//         Graphics,
//         Physics,
//         Memory,
//         IO
//     };
//
//     struct [[nodiscard]] Result
//     {
//         // 64-bit packed structure
//         uint32_t m_code     : 16; // 0-65535 (Plenty for error codes)
//         uint32_t m_category : 8;  // 0-255 (Categories)
//         uint32_t m_severity : 4;  // 0-15 (Severity levels)
//         uint32_t m_reserved : 4;  // Extra bits for flags (e.g., bool is_deferred)
//         uint32_t m_padding  : 32; // Explicit padding to force 64-bit size if needed
//
//         // Fast constructor
//         inline Result(uint16_t code, Category category = Category::General, uint8_t severity = 0)
//             : m_code(code),
//               m_category(static_cast<uint8_t>(category)),
//               m_severity(severity),
//               m_reserved(0),
//               m_padding(0) {}
//
//         // Extremely fast check: compilers will optimize this to a simple
//         // comparison against zero for the whole 64-bit register
//         [[nodiscard]] inline bool Success() const noexcept { return m_code == 0; }
//     };
// }
//
// how should i approach this. like i have modules like engine devtools backends and i will propably have
// some other modules or libs in the future. PLus I DONT WANt to create deal with a lot of problems.
// so i thin i want to have a dynomically allocater id to each problem
//  *
//  *
//  *
//  */