#ifndef UTIL_BGM_HPP
#define UTIL_BGM_HPP

#include "pch.hpp" // IWYU pragma: export

namespace Util {
/**
 * @class BGM
 * @brief Class for handling background music.
 * @note There can be only one BGM object playing at a time.
 *            If a BGM object is playing and another BGM object is played,
 *            the previous one will stop playing.
 * @see Util::SFX
 */
class BGM {
public:
    BGM() = delete;

    /**
     * @brief Constructor that initializes the BGM object and loads the music
     *            from the specified file path.
     * @param path The file path of the background music to be loaded.
     */
    explicit BGM(const std::string &path);

    /**
     * @brief Deleted copy constructor to prevent copying of BGM objects.
     */
    BGM(const BGM &) = delete;

    /**
     * @brief Deleted copy assignment operator to prevent copying of BGM
     *            objects.
     */
    BGM &operator=(const BGM &) = delete;

    /**
     * @brief Retrieves the current volume of the background music.
     * @return The current volume of the background music.
     */
    int GetVolume() const;

    /**
     * @brief Sets the volume of the background music.
     * @param volume The desired volume level for the background music. The
     *              valid range is [0, 128]. <br>
     *              A value of 0 mutes the music, and a value of 128
     *              sets the maximum volume.
     */
    void SetVolume(int volume);

    /**
     * @brief Loads the background music from the specified file path.
     * @param path The file path of the background music to be loaded.
     */
    void LoadMedia(const std::string &path);

    /**
     * @brief Increases the volume of the background music by one.
     * @param step The amount to increase the volume by.
     */
    void VolumeUp(int step = 1);

    /**
     * @brief Decreases the volume of the background music by one.
     * @param step The amount to decrease the volume by.
     */
    void VolumeDown(int step = 1);

    /**
     * @brief Plays the background music.
     * @param loop The number of times the music will loop.<br>
     *             A value of -1 means it will loop indefinitely.<br>
     *             A non-negative value means it will loop that many times.<br>
     *             Default value: -1
     * @note Calling this function stops any currently playing music and plays.
     */
    void Play(int loop = -1);

    /**
     * @brief Fades in the background music gradually.
     * @param tick The duration of the fade-in effect, in milliseconds.
     * @param loop The number of times the music will loop after the fade-in is
     *                      complete.<br> A value of -1 means it will loop
     * indefinitely.
     */
    void FadeIn(int tick, int loop = -1);

    /**
     * @brief Fades out the background music gradually.
     * @param tick The duration of the fade-out effect, in milliseconds.
     */
    void FadeOut(int tick);

    /**
     * @brief Pauses the currently playing background music.
     * @note This function has no effect if there is no background music
     * currently playing.
     */
    void Pause();

    /**
     * @brief Resumes the paused background music.
     * @note This function has no effect if there is no paused background music.
     */
    void Resume();
 /**
  * @brief 計時器回呼函數，用於延遲播放音樂。
  */
 static Uint32 TimerCallback(Uint32 interval, void *param);

 /**
  * @brief 非阻塞延遲播放背景音樂。
  * @param delay 延遲時間（毫秒）。
  * @param loop 播放的循環次數，預設 -1 表示無限循環。
  */
 void DelayedPlayAsync(int delay, int loop = -1);
private:
    // Use functor instead of function pointer as deleter to
    // make it less confusing.
    struct MusicDeleter {
        void operator()(Mix_Music *music) { Mix_FreeMusic(music); }
    };

    std::unique_ptr<Mix_Music, MusicDeleter> m_BGM;
};

} // namespace Util

#endif // UTIL_BGM_HPP
