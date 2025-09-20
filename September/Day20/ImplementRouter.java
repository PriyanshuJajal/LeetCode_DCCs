// LEETCODE 3508. Implement Router

// Design a data structure that can efficiently manage data packets in a network router. Each data packet consists of the following attributes:

// source: A unique identifier for the machine that generated the packet.
// destination: A unique identifier for the target machine.
// timestamp: The time at which the packet arrived at the router.
// Implement the Router class:

// Router(int memoryLimit): Initializes the Router object with a fixed memory limit.

// memoryLimit is the maximum number of packets the router can store at any given time.
// If adding a new packet would exceed this limit, the oldest packet must be removed to free up space.
// bool addPacket(int source, int destination, int timestamp): Adds a packet with the given attributes to the router.

// A packet is considered a duplicate if another packet with the same source, destination, and timestamp already exists in the router.
// Return true if the packet is successfully added (i.e., it is not a duplicate); otherwise return false.
// int[] forwardPacket(): Forwards the next packet in FIFO (First In First Out) order.

// Remove the packet from storage.
// Return the packet as an array [source, destination, timestamp].
// If there are no packets to forward, return an empty array.
// int getCount(int destination, int startTime, int endTime):

// Returns the number of packets currently stored in the router (i.e., not yet forwarded) that have the specified destination and have timestamps in the inclusive range [startTime, endTime].
// Note that queries for addPacket will be made in increasing order of timestamp.

 

// Example 1:

// Input:
// ["Router", "addPacket", "addPacket", "addPacket", "addPacket", "addPacket", "forwardPacket", "addPacket", "getCount"]
// [[3], [1, 4, 90], [2, 5, 90], [1, 4, 90], [3, 5, 95], [4, 5, 105], [], [5, 2, 110], [5, 100, 110]]

// Output:
// [null, true, true, false, true, true, [2, 5, 90], true, 1]

// Explanation

// Router router = new Router(3); // Initialize Router with memoryLimit of 3.
// router.addPacket(1, 4, 90); // Packet is added. Return True.
// router.addPacket(2, 5, 90); // Packet is added. Return True.
// router.addPacket(1, 4, 90); // This is a duplicate packet. Return False.
// router.addPacket(3, 5, 95); // Packet is added. Return True
// router.addPacket(4, 5, 105); // Packet is added, [1, 4, 90] is removed as number of packets exceeds memoryLimit. Return True.
// router.forwardPacket(); // Return [2, 5, 90] and remove it from router.
// router.addPacket(5, 2, 110); // Packet is added. Return True.
// router.getCount(5, 100, 110); // The only packet with destination 5 and timestamp in the inclusive range [100, 110] is [4, 5, 105]. Return 1.
// Example 2:

// Input:
// ["Router", "addPacket", "forwardPacket", "forwardPacket"]
// [[2], [7, 4, 90], [], []]

// Output:
// [null, true, [7, 4, 90], []]

// Explanation

// Router router = new Router(2); // Initialize Router with memoryLimit of 2.
// router.addPacket(7, 4, 90); // Return True.
// router.forwardPacket(); // Return [7, 4, 90].
// router.forwardPacket(); // There are no packets left, return [].
 

// Constraints:

// 2 <= memoryLimit <= 105
// 1 <= source, destination <= 2 * 105
// 1 <= timestamp <= 109
// 1 <= startTime <= endTime <= 109
// At most 105 calls will be made to addPacket, forwardPacket, and getCount methods altogether.
// queries for addPacket will be made in increasing order of timestamp.


// 🚀 Approach (JAVA)
// Use a Deque<Packet> to maintain packet order and enforce memory limits.
// Encode each packet uniquely as a string and store in a Set<String> to detect duplicates.
// Maintain a Map<Integer, List> to track timestamps per destination.
// On addPacket, evict the oldest if memory is full, update all structures, and insert the new packet.
// On forwardPacket, remove the oldest packet and clean up its metadata.
// On getCount, use binary search to count timestamps in the range [startTime, endTime].




class Packet {
    int source;
    int destination;
    int timestamp;

    public Packet(int source, int destination, int timestamp) {
        this.source = source;
        this.destination = destination;
        this.timestamp = timestamp;
    }
}

class Router {
    private int memoryLimit;
    private Deque<Packet> q;
    private Set<String> duplicates;
    private Map<Integer, List<Integer>> timeStampsDestination;

    public Router(int memoryLimit) {
        this.memoryLimit = memoryLimit;
        this.q = new ArrayDeque<>();
        this.duplicates = new HashSet<>();
        this.timeStampsDestination = new HashMap<>();
    }

    private void findAndRemove(List<Integer> list, int val) {
        if (!list.isEmpty() && list.get(0) == val) {
            list.remove(0);
        }
    }

    private String encode(Packet p) {
        return p.source + "#" + p.destination + "#" + p.timestamp;
    }
    
    public boolean addPacket(int source, int destination, int timestamp) {
        String key = source + "#" + destination + "#" + timestamp;
        if (duplicates.contains(key)) return false;

        if (q.size() == memoryLimit) {
            Packet oldest = q.pollFirst();
            duplicates.remove(encode(oldest));
            findAndRemove(timeStampsDestination.get(oldest.destination) , oldest.timestamp);
        }

        Packet newPacket = new Packet(source, destination, timestamp);
        q.addLast(newPacket);
        duplicates.add(key);
        timeStampsDestination.computeIfAbsent(destination, k -> new ArrayList<>()).add(timestamp);

        return true;
    }
    
    public int[] forwardPacket() {
        if (q.isEmpty()) return new int[0];

        Packet pcktToForward = q.pollFirst();
        duplicates.remove(pcktToForward.source + "#" + pcktToForward.destination + "#" + pcktToForward.timestamp);

        List<Integer> timestamps = timeStampsDestination.get(pcktToForward.destination);
        if (timestamps != null && !timestamps.isEmpty() && timestamps.get(0) == pcktToForward.timestamp) 
            timestamps.remove(0);

        return new int[]{pcktToForward.source , pcktToForward.destination , pcktToForward.timestamp};
    }

    private int findLowerBoundIndex(List<Integer> list, int target) {
        int index = Collections.binarySearch(list, target);
        if (index < 0) {
            return -(index + 1); 
        }

        while (index > 0 && list.get(index - 1).equals(target)) {
            index--;
        }
        return index;
    }

    public int getCount(int destination, int startTime, int endTime) {
        if (!timeStampsDestination.containsKey(destination)) {
            return 0;
        }
        List<Integer> timestamps = timeStampsDestination.get(destination);

        int startIdx = findLowerBoundIndex(timestamps, startTime);
        int endIdx = findLowerBoundIndex(timestamps, endTime + 1);

        return endIdx - startIdx;
    }
}

/**
 * Your Router object will be instantiated and called as such:
 * Router obj = new Router(memoryLimit);
 * boolean param_1 = obj.addPacket(source,destination,timestamp);
 * int[] param_2 = obj.forwardPacket();
 * int param_3 = obj.getCount(destination,startTime,endTime);
 */