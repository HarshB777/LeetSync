#pragma GCC optimize ("O3")

class Solution {
private:
    typedef unsigned long long u64_t;
    typedef unsigned int       u32_t;
    typedef unsigned short     u16_t;
    typedef unsigned char      u8_t;

    static constexpr u8_t FWIDTH = 20;
    static constexpr u64_t FMASK = (1ull << FWIDTH) - 1u;;

    static u64_t setfield(const u64_t v, const u8_t exp, const u32_t value)
    __attribute__((always_inline)) {
        return (v & ~(FMASK << exp)) + (u64_t(value) << exp);
    }

public:
    static int garbageCollection(vector<string>& garbage, vector<int>& travel) {
        const u32_t n = travel.size();
        u64_t ends = 0;
        u32_t rtime = 0, count = garbage.front().length();
        for (u32_t i = 1; i <= n; i++) {
            const string &a = garbage[i];
            const char *ac = a.c_str();
            u8_t m = a.length();
            count += m;
            if (m >= 8u) {
                const u64_t vk = *reinterpret_cast<const u64_t*>(ac) - 0x4747474747474747ull,
                            vexp = ((vk >> 2) & 0x3F3F3F3F3F3F3F3Full) * 20u;
                ends = setfield(ends, vexp & 0xFFu, i);
                ends = setfield(ends, (vexp >> 8) & 0xFFu, i);
                ends = setfield(ends, (vexp >> 16) & 0xFFu, i);
                ends = setfield(ends, (vexp >> 24) & 0xFFu, i);
                ends = setfield(ends, (vexp >> 32) & 0xFFu, i);
                ends = setfield(ends, (vexp >> 40) & 0xFFu, i);
                ends = setfield(ends, (vexp >> 48) & 0xFFu, i);
                ends = setfield(ends, (vexp >> 56) & 0xFFu, i);
                ac += 8u;
                m -= 8u;
            }
            if (m >= 4u) {
                const u32_t vk = *reinterpret_cast<const u32_t*>(ac) - 0x47474747u,
                            vexp = ((vk >> 2) & 0x3F3F3F3Fu) * 20u;
                ends = setfield(ends, vexp & 0xFFu, i);
                ends = setfield(ends, (vexp >> 8) & 0xFFu, i);
                ends = setfield(ends, (vexp >> 16) & 0xFFu, i);
                ends = setfield(ends, (vexp >> 24) & 0xFFu, i);
                ac += 4u;
                m -= 4u;
            }
            if (m >= 2u) {
                const u16_t vk = *reinterpret_cast<const u16_t*>(ac) - 0x4747u,
                            vexp = ((vk >> 2) & 0x3F3Fu) * 20u;
                ends = setfield(ends, vexp & 0xFFu, i);
                ends = setfield(ends, (vexp >> 8) & 0xFFu, i);
                ac += 2u;
                m -= 2u;
            }
            if (m >= 1u) {
                const u8_t k = *ac - 'G', exp = (k & (k - 1u)) * 5u;
                ends = setfield(ends, exp, i);
                ac += 1u;
                m--;
            }
            travel[i-1u] = rtime += travel[i-1u];
        }
        const u32_t ep = ends >> FWIDTH * 2u, em = (ends >> FWIDTH) & FMASK, eg = ends & FMASK;
        return (ep ? travel[ep-1u] : 0u) + (em ? travel[em-1u] : 0u) +
               (eg ? travel[eg-1u] : 0u) + count;

    }
};

auto init = []() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 'c';
}();