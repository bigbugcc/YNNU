const app = new Vue({
    el: '#app',
    data: {
        cards: {
            self : {
                hand: [],
                show: [],
            },
            playerTop : {
                hand: [],
                show: [],
            },
            playerLeft : {
                hand: [],
                show: [],
            },
            playerRight : {
                hand: [],
                show: [],
            }
        }
    },
    // 在 `methods` 对象中定义方法
    methods: {
        getStyle(card) {
            return `background-position: ${-69 * card.col}px ${-105 * card.row}px;`;
        },
        reset() {
            const cards = [];

            // 生成52张牌
            for (let row = 0; row < 4; row++) {
                for(let col = 0; col < 13; col++) {
                    cards.push({ id: `c-${Utils.prefixZero(row, 2)}-${Utils.prefixZero(col, 2)}`,  row, col })
                }
            }
            
            for (let i = 0; i < 50; i++) {
                const a = Math.floor(Math.random() * cards.length);
                const b = Math.floor(Math.random() * cards.length);
                const t = cards[a];
                cards[a] = cards[b]; cards[b] = t;
            }

            this.cards.self.hand = cards.splice(0, 13).sort((a, b)=> (a.id < b.id) ? -1: 1);
            this.cards.playerTop.show = cards.splice(0, 13);
            this.cards.playerLeft.show = cards.splice(0, 13);
            this.cards.playerRight.show = cards.splice(0, 13);


        }
    }
})

function getData() {
    $.ajax({
        type:"POST",
        url:"/Poker_war/PokerData",
        dataType:"json",
        success:function(data){
            if(data.success){
                $("searchResult").html(data.msg);
            }else{
                $("#searchResult").html("出现错误：" + data.msg);
            }
        },
        error:function(jqXHR){
            aler("发生错误："+ jqXHR.status);
        }
    });
}