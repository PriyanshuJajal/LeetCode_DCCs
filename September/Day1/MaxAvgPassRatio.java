// LEETCODE 1792. Maximum Average Pass Ratio

// There is a school that has classes of students and each class will be having a final exam. You are given a 2D integer array classes, where classes[i] = [passi, totali]. You know beforehand that in the ith class, there are totali total students, but only passi number of students will pass the exam.

// You are also given an integer extraStudents. There are another extraStudents brilliant students that are guaranteed to pass the exam of any class they are assigned to. You want to assign each of the extraStudents students to a class in a way that maximizes the average pass ratio across all the classes.

// The pass ratio of a class is equal to the number of students of the class that will pass the exam divided by the total number of students of the class. The average pass ratio is the sum of pass ratios of all the classes divided by the number of the classes.

// Return the maximum possible average pass ratio after assigning the extraStudents students. Answers within 10-5 of the actual answer will be accepted.

 

// Example 1:

// Input: classes = [[1,2],[3,5],[2,2]], extraStudents = 2
// Output: 0.78333
// Explanation: You can assign the two extra students to the first class. The average pass ratio will be equal to (3/4 + 3/5 + 2/2) / 3 = 0.78333.
// Example 2:

// Input: classes = [[2,4],[3,9],[4,5],[2,10]], extraStudents = 4
// Output: 0.53485
 

// Constraints:

// 1 <= classes.length <= 105
// classes[i].length == 2
// 1 <= passi <= totali <= 105
// 1 <= extraStudents <= 105


// 🚀 Approach
// Define a gain function that calculates the improvement in pass ratio when one passing student is added.
// Use a max-heap (priority queue) to always pick the class with the highest gain.
// Initially, push all classes into the heap with their calculated gain.
// For each extra student:
//     Pop the class with the highest gain.
//     Add a passing student (increment both pass and total).
//     Recalculate gain and push the updated class back into the heap.
// After distributing all extra students, compute the average pass ratio across all classes.



class Solution {
    private static class ClassInfo {
        int pass;
        int total;
        double gain;

        ClassInfo(int pass , int total) {
            this.pass = pass;
            this.total = total;
            this.gain = calculateGain(pass , total);    
        }

        private static double calculateGain(double pass , double total) {
            if (pass == total) return 0.0;
            return ((pass + 1) / (total + 1)) - (pass / total);
        }
    }

    public double maxAverageRatio(int[][] classes, int extraStudents) {
        PriorityQueue<ClassInfo> pq = new PriorityQueue<>(
            (a , b) -> Double.compare(b.gain , a.gain)
        );

        for (int[] c : classes) pq.offer(new ClassInfo(c[0] , c[1]));

        for (int i = 0; i < extraStudents; i++) {
            ClassInfo top = pq.poll();
            if (top == null) break;

            ClassInfo updatedClass = new ClassInfo(top.pass + 1 , top.total + 1);
            pq.offer(updatedClass);
        }

        double totalRatioSum = 0.0;
        int n = classes.length;

        while(!pq.isEmpty()) {
            ClassInfo classData = pq.poll();
            totalRatioSum += (double)classData.pass / classData.total;
        }
        return totalRatioSum / n;
    }
}