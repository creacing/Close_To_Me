<template>
  <div class="archive">
    <RouterLink :to="`/article${archive.path}`" v-for="archive in archiveList" :key="archive">
      <div class="item flex-row">
        <span>{{ archive.title }}</span>
        <span>{{ archive.date }}</span>
      </div>
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
.archive {
  .item {
    padding: 0.5rem 1rem;
    justify-content: space-between;
  }

  .item:hover {
    color: var(--color-blue);
  }
}
</style>