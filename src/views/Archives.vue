<template>
  <div class="collapse wrap">
    <h2 class="item header">
      <RouterLink to>归档</RouterLink>
      <small>/</small>
      {{ articlesNum }}
      <!-- <small class="cheers">Practice makes perfect</small> -->
    </h2>
    <RouterLink :to="`/article${archive.path}`" v-for="archive in archiveList" :key="archive">
      <h3 class="item section">
        <span class="bg">{{ archive.date.split("-")[0] }} 年</span>
        <small>/</small>
        <span class="bg">{{ archive.date.split("-")[1] }} 月</span>
        <small>/</small>
        <span class="bg">{{ archive.date.split("-")[2] }} 月</span>
        <small>/</small>
        <span class="bg">{{ archive.title }} 月</span>
      </h3>
    </RouterLink>
  </div>
</template>

<script setup>
import { RouterLink } from "vue-router";
import { store } from "@/stores/store.js";
import { ref } from "vue";
const state = store();
const posts = state.postsDic;

const articlesNum = state.postsDic.size;
const archiveList = ref([]);
for (const post of posts) {
  archiveList.value.push(post[1]);
}
</script>
<style scoped lang='scss'>
.item {
  display: flex;
  // justify-content: space-around;
  .bg {
    // background-color: #fff;
    padding: 0.125rem;
  }
}
</style>