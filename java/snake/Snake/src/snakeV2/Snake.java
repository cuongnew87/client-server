/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package snakeV2;

import java.awt.Color;
import java.awt.Graphics;
import java.util.List;
import java.util.ArrayList;

/**
 *
 * @author Ngua gia
 */
public class Snake {

    List<Point> snakePoints;
    int xDir, yDir;
    boolean isMoving, elongate;
    final int STARTSIZE = 20, STARTX = 150, STARTY = 150;
    long speed = 40;

    // init Snake
    public Snake() {
        snakePoints = new ArrayList<Point>();
        xDir = 0;
        yDir = 0;
        isMoving = false;
        elongate = false;
        snakePoints.add(new Point(STARTX, STARTY));
        for (int i = 1; i < STARTSIZE; i++) {
            snakePoints.add(new Point(STARTX - i * 4, STARTY));
        }
    }

    public void draw(Graphics g) {
        g.setColor(Color.BLACK);
        for (Point p : snakePoints) {
            g.fillRect(p.getX(), p.getY(), 4, 4);
        }
    }

    public void move() {
        if (isMoving) {
            Point temp = snakePoints.get(0);
            Point last = snakePoints.get(snakePoints.size() - 1);
            Point newStart = new Point(temp.getX() + xDir * 4, temp.getY() + yDir * 4);
            for (int i = snakePoints.size() - 1; i >= 1; i--) {
                snakePoints.set(i, snakePoints.get(i - 1));
            }
            snakePoints.set(0, newStart);
            if (elongate) {
                snakePoints.add(last);
                elongate = false;
            }
        }
    }

    public boolean snakeCollistion() {
        int x = this.getX();
        int y = this.getY();
        for (int i = 1; i < snakePoints.size(); i++) {
            if (snakePoints.get(i).getX() == x && snakePoints.get(i).getY() == y) {
                return true;
            }
        }
        return false;
    }

    public boolean isMoving() {
        return isMoving;
    }

    public void setIsMoving(boolean b) {
        isMoving = b;
    }

    public int getXDir() {
        return xDir;
    }

    public int getYDir() {
        return yDir;
    }

    public void setXDir(int x) {
        xDir = x;
    }

    public void setYDir(int y) {
        yDir = y;
    }

    //X position of the head of the snake
    public int getX() {
        return snakePoints.get(0).getX();
    }

    public int getY() {
        return snakePoints.get(0).getY();
    }

    public void setElongate(boolean b) {
        elongate = b;
    }
}
