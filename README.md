由于游戏的各个Row的事件是相对独立的，所以进行开发的时候，可以先构建一个Row系统

每个Blank 为一个Struct，可以容纳Union在其中进行活动和交互

Struct 的作用不仅仅是Union交互的框架，也通过和同Row的其他Struct交互进行Union的跨框架交流

Union之间使用信号槽进行交流，Struct受到信号并寻找对应的槽，并且对加入Struct的Union进行事件循环

Struct中定义一个数组，其中每个元素以list的形式存放该位置上的一系列Union，list以队列的形式进行处理，
在Struct的事件循环中，从两端来的Union在数组中都向中间移动一个位置，当两端的第一个list相遇（一端的list头的下一个位置为另一端的list头），
数组中央设置一个标志位，是Struc本身属性的体现，数组中的list在遇到这个标志位的时候需要和Struct进行特殊交互

另设置一工厂，提供构建各种Struct及其派生类实例的功能

Struct带有生成Union的功能