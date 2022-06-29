package stack_queue;

import java.util.Stack;

class Solution {
    /**
     * If the asteroid is with + sign, simply push onto stack since it can't collide, 
     * irrespective of whether the stack top is + (both same direction & hence can't collide) 
     * or stack top is - (since both in opposite direction & the stack top is present to left of the asteroid & also moving left, 
     * they can't collide)
     * 
     * If the asteroid is with - sign, there can be couple of cases :
     *      1. if stack top is +ve & absolute value is lesser than the asteroid, then it has to be blown off, so pop it off.
     *      2. if the stack top is also -ve, simply push the asteroid, no question of collision since both move in left direction.
     *      3. if the absolute value of asteroid & stack top are same, both would be blown off, so effectively pop off from stack & do nothing with the current asteroid.
     */
    public int[] asteroidCollision(int[] A) {
        Stack<Integer> s = new Stack<>();
        for (int num : A) {
            if (num > 0) 
                s.push(num);
            else { // num < 0
                while (!s.isEmpty() && s.peek() > 0 && s.peek() < Math.abs(num)) 
                    s.pop();
                if (s.isEmpty() || s.peek() < 0)
                    s.push(num);
                else if (Math.abs(num) == s.peek())
                    s.pop();
            }
        }
        
        int[] res = new int[s.size()];
        for (int j = s.size() - 1; j >= 0; j--) {
            res[j] = s.pop();
        }
        return res;
    }
}