int minTime(vector<string> park) {
//     // BẢNG COST[i][j]: đường đi ngắn nhất từ xe i đến chỗ j, dùng BFS

//     // N cars, M parking slot
//     // build a cost matrix cost[i][j] = cost of getting from car i to 
//     //      parking spot j, by doing a BFS
//     // vertices 0, 1, ..., N - 1 will represent the cars, and 
//     //      vertices N, N + 1, ..., N + M - 1 will represent
//     //          the parking spots; N + M will be the super-sink
//     int D = 0, sink = N + M;
//     // car_match[i] = j : xe i đỗ ở chỗ j
//     // prev_match[i] = j : chỗ đỗ xe i có xe j
//     int car_match[105], park_match[105];
//     memset(car_match, -1, sizeof(car_match));
//     memset(park_match, -1, sizeof(park_match));
//     // duyệt tất cả xe, mỗi lần duyệt xe thì 
//     for(int source = 0; source < N; ++source) {
//         // chưa cho ... duyệt cả 
//         bool visited[210];
//         memset(visited, false, sizeof(visited));
//         // from 
//         int from[210];
//         memset(from, -1, sizeof(from));
//         priority_queue<node> pq;
//         // where, cost, from 
//         pq.push(node(source, 0, -1));
//         while(!pq.empty()) {
//             // cost: giá trị 
//             int cst = pq.top().cost;
//             // where: đang xét cái gì ?  
//             int where = pq.top().where;
//             // from: từ đâu 
//             int _from = pq.top().from;
//             pq.pop();
//             // đã duyệt vị trí này 
//             if(visited[where]) continue;
//             visited[where] = true;
//             // vị trí này từ from ?
//             from[where] = _from;
//             // nếu là xe, xe [where] thử tất cả M chỗ đỗ xe 
//             if(where < N) {
//                 // duyệt tất cả các chỗ đỗ
//                 for(int i = 0; i < M; ++i) {
//                     // nếu không thể đến hoặc xe này đã đỗ ở chỗ này thì bỏ qua 
//                     if(cost[where][i] == INF || car_match[where] == i) continue;
//                     int ncst = max(cst, cost[where][i]);
//                     // chỗ đỗ xe thứ i là N + i 
//                     pq.push(node(N + i, ncst, where));
//                 }
//             }
//             else {
//                 // nếu chỗ đỗ xe này is unmatched thì tìm đường đi hợp lệ với giá trị nhỏ nhất 
//                 if(park_match[where - N] == -1) {
//                     from[sink] = where;
//                     // Nếu D cần tăng thì tăng 
//                     D = max(D, cst);
//                     break;
//                 }
//                 int ncst = max(cst, cost[next][where]);
//                 pq.push(node(next, ncst, where));
//             }
//         }
//         int where = from[sink];
//         // nếu không có đường đi hợp lệ trả về -1 
//         if (where == -1)
//             return -1;
//         int prev = from[where];
//         // nếu where là chỗ đỗ xe thì cạnh (prev, where) is a foward edge and the match must be updated
//         if (where >= N) {
//             // xe [prev] đỗ ở [where] là chỗ đỗ xe 
//             car_match[prev] = where;
//             // vị trí đỗ xe ở [where] có xe prev
//             park_match[where - N] = prev;
//         }
//         where = prev;
//     }
//     return D;
// }