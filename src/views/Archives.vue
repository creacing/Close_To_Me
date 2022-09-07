<template>
  <div class="collapse wrap">
    <h2 class="item header">
      <a href="/" data-pjax-state>首页</a>
      <small>/</small>
      目前共计 {{articlesNum}}
      篇文章。
      <small class="cheers">Practice makes perfect</small>
    </h2>
    <h3 class="item section" v-for="archive in archiveList">
      <router-link href="/archives/2022" data-pjax-state>{{article.year}} 年</router-link>
      <small>/</small>
      <router-link href="/archives/2022/07" data-pjax-state>{{article.month}} 月</router-link>
      <!-- <small>( 5 )</small> -->
    </h3>
  </div>
</template>

<script setup>
const articlesNum = 100
const archiveList = []
</script>
