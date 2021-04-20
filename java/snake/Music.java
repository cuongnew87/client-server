/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package snakeV2;

import java.io.File;
import javax.sound.sampled.AudioInputStream;
import javax.sound.sampled.AudioSystem;
import javax.sound.sampled.Clip;

/**
 *
 * @author Ngua gia
 */
public class Music {

    Clip clip;
    long clipPosition;

    public Clip getClip() {
        return clip;
    }

    public void setClip(Clip clip) {
        this.clip = clip;
    }

    public void playMusic(String musicLocation) {
        try {
            File musicPath = new File(musicLocation);
            if (musicPath.exists()) {
                AudioInputStream audioInput = AudioSystem.getAudioInputStream(musicPath);
                clip = AudioSystem.getClip();
                clip.open(audioInput);
                clip.start();
                clip.loop(Clip.LOOP_CONTINUOUSLY);
            }
        } catch (Exception e) {
        }
    }

    public void stopMusic() {
        try {
            clip.stop();
            clip.close();
        } catch (Exception e) {
        }
    }

    public void pauseMusic() {
        clipPosition = clip.getMicrosecondPosition();
        clip.stop();
    }

    public void resumeMusic() {
        clip.setMicrosecondPosition(clipPosition);
        clip.start();
    }
}
