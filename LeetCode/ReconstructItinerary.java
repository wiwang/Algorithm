


/*
Given a list of airline tickets represented by pairs of departure and arrival airports [from, to], reconstruct the itinerary in order. All of the tickets belong to a man who departs from JFK. Thus, the itinerary must begin with JFK.

Note:

    If there are multiple valid itineraries, you should return the itinerary that has the smallest lexical order when read as a single string. For example, the itinerary ["JFK", "LGA"] has a smaller lexical order than ["JFK", "LGB"].
    All airports are represented by three capital letters (IATA code).
    You may assume all tickets form at least one valid itinerary.

Example 1:
tickets = [["MUC", "LHR"], ["JFK", "MUC"], ["SFO", "SJC"], ["LHR", "SFO"]]
Return ["JFK", "MUC", "LHR", "SFO", "SJC"].

Example 2:
tickets = [["JFK","SFO"],["JFK","ATL"],["SFO","ATL"],["ATL","JFK"],["ATL","SFO"]]
Return ["JFK","ATL","JFK","SFO","ATL","SFO"].
Another possible reconstruction is ["JFK","SFO","ATL","JFK","ATL","SFO"]. But it is larger in lexical order. 
*/


package Q332;

import java.util.ArrayList;
import java.util.HashMap;
import java.util.List;
import java.util.Map;
import java.util.PriorityQueue;
import java.util.Stack;

public class Solution {

    public static List<String> findItinerary(String[][] tickets) {
        List<String> ans = new ArrayList<String>();
        if (tickets.length < 1)
            return ans;
        Map<String, PriorityQueue<String>> myMap = new HashMap<String, PriorityQueue<String>>();
        for (int i = 0; i < tickets.length; i++) {
            if(!myMap.containsKey(tickets[i][0])) myMap.put(tickets[i][0], new PriorityQueue<String>());
            myMap.get(tickets[i][0]).add(tickets[i][1]);
        }



        String now = "JFK";
        Stack<String> s = new Stack<String>();
        for(int i = 0; i < tickets.length; i++) {
            while(!myMap.containsKey(now) || myMap.get(now).isEmpty()) {
                s.push(now);
                now = ans.remove(ans.size()-1);
            }
            ans.add(now);
            now = myMap.get(now).poll();
        }
        ans.add(now);
        while(!s.isEmpty()) ans.add(s.pop());
        return ans;
    }


//  public static void main(String[] args) {
//      String[][] tickets ={{"AXA","EZE"},{"EZE","AUA"},{"ADL","JFK"},{"ADL","TIA"},{"AUA","AXA"},{"EZE","TIA"},{"EZE","TIA"},{"AXA","EZE"},{"EZE","ADL"},{"ANU","EZE"},{"TIA","EZE"},{"JFK","ADL"},{"AUA","JFK"},{"JFK","EZE"},{"EZE","ANU"},{"ADL","AUA"},{"ANU","AXA"},{"AXA","ADL"},{"AUA","JFK"},{"EZE","ADL"},{"ANU","TIA"},{"AUA","JFK"},{"TIA","JFK"},{"EZE","AUA"},{"AXA","EZE"},{"AUA","ANU"},{"ADL","AXA"},{"EZE","ADL"},{"AUA","ANU"},{"AXA","EZE"},{"TIA","AUA"},{"AXA","EZE"},{"AUA","SYD"},{"ADL","JFK"},{"EZE","AUA"},{"ADL","ANU"},{"AUA","TIA"},{"ADL","EZE"},{"TIA","JFK"},{"AXA","ANU"},{"JFK","AXA"},{"JFK","ADL"},{"ADL","EZE"},{"AXA","TIA"},{"JFK","AUA"},{"ADL","EZE"},{"JFK","ADL"},{"ADL","AXA"},{"TIA","AUA"},{"AXA","JFK"},{"ADL","AUA"},{"TIA","JFK"},{"JFK","ADL"},{"JFK","ADL"},{"ANU","AXA"},{"TIA","AXA"},{"EZE","JFK"},{"EZE","AXA"},{"ADL","TIA"},{"JFK","AUA"},{"TIA","EZE"},{"EZE","ADL"},{"JFK","ANU"},{"TIA","AUA"},{"EZE","ADL"},{"ADL","JFK"},{"ANU","AXA"},{"AUA","AXA"},{"ANU","EZE"},{"ADL","AXA"},{"ANU","AXA"},{"TIA","ADL"},{"JFK","ADL"},{"JFK","TIA"},{"AUA","ADL"},{"AUA","TIA"},{"TIA","JFK"},{"EZE","JFK"},{"AUA","ADL"},{"ADL","AUA"},{"EZE","ANU"},{"ADL","ANU"},{"AUA","AXA"},{"AXA","TIA"},{"AXA","TIA"},{"ADL","AXA"},{"EZE","AXA"},{"AXA","JFK"},{"JFK","AUA"},{"ANU","ADL"},{"AXA","TIA"},{"ANU","AUA"},{"JFK","EZE"},{"AXA","ADL"},{"TIA","EZE"},{"JFK","AXA"},{"AXA","ADL"},{"EZE","AUA"},{"AXA","ANU"},{"ADL","EZE"},{"AUA","EZE"}};
//      System.out.println(findItinerary(tickets).toString());
//  }

}


