<template>
  <div class="collapse wrap">
    <h2 class="item title">
      <router-link to="/" data-pjax-state>首页</router-link>
      <small>/</small>
      目前共计 {{tagsNum}}
    </h2>
    <div class="tag cloud">
      <router-link
        v-for="tag in tagList"
        :to="tag.path"
        :style="{'font-size': tag.articlesNum>20?'20px':tag.articlesNum<14?'14px':`${tag.articlesNum}px`, 'color': cloudColorList[tag.articlesNum % cloudColorList.length ]}"
        data-pjax-state
      >{{tag.name}}</router-link>
    </div>
  </div>
</template>
<script setup>
import { RouterLink } from "vue-router";
import config from "../../public/config";
const { cloudColorList } = config
const tagsNum = 100
const tagList = [
  { name: 'demo', path: '', articlesNum: 1 },
  { name: 'demo', path: '', articlesNum: 2 },
  { name: 'demo', path: '', articlesNum: 3 },
  { name: 'demo', path: '', articlesNum: 4 },
  { name: 'demo', path: '', articlesNum: 5 },
  { name: 'demo', path: '', articlesNum: 6 },
  { name: 'demo', path: '', articlesNum: 7 },
  { name: 'demo', path: '', articlesNum: 8 },
  { name: 'demo', path: '', articlesNum: 9 },
  { name: 'demo', path: '', articlesNum: 10 },
  { name: 'demo', path: '', articlesNum: 11 },
  { name: 'demo', path: '', articlesNum: 12 },
  { name: 'demo', path: '', articlesNum: 13 },
  { name: 'demo', path: '', articlesNum: 14 },
  { name: 'demo', path: '', articlesNum: 15 },
  { name: 'demo', path: '', articlesNum: 16 },
  { name: 'demo', path: '', articlesNum: 17 },
  { name: 'demo', path: '', articlesNum: 18 },
  { name: 'demo', path: '', articlesNum: 19 },
  { name: 'demo', path: '', articlesNum: 20 },
  { name: 'demo', path: '', articlesNum: 21 },

]

</script>
