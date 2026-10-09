# Project P24

An experimental prime solving program designed to predict and list all prime numbers within n=5 to a range. 
(Designed in late 2021)

## Performance

    Timed with an i5-10400 Processor:
- n = 1,000,000: 0.052 seconds average
- n = 10,000,000 1.32 seconds average
- n = 100,000,000: 36.9 seconds average

Across inputs from 100,000 to 100,000,000, p24 __consistently outperforms trial division by about 25-40%__. 
However, Power law regression yields a higher exponent value in comparison. This means that Trial division is actually faster, but only after N=150,000,000,000. This scenario would take about __23 days__ of straight runtime to observe. 

    Chart comparing the runtime of P24 and Trial Division:
![Graph of Comparison to Trial division](p24_chart_20261009.png)

    Graph comparing the runtime of P24 and Trial Division:
![Chart of Comparison to Trial division](p24_graph_20261009.png)

## More details
This algorithm was designed without using any mathematical intuition. The process involves predicting numbers by squaring the current n and tracking the next candidate. It is very similar to 6k +/- 1 methods from what I've seen.


    Big picture:
Ultimately, I designed this algorithm to prove to myself that math and logic in their complexities are ultimately equivalent from a theoretical standpoint. Whether that is true or not, I still do not know. What I do know is that I do not plan on future optimizations. Doing research on prime numbers is like betting on a dead horse. Prime numbers are a neverending sequence of cyclical patterns that simply never end.
