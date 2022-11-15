<template>
  <div class="tag">
    <RouterLink
      class="link"
      :key="tag"
      v-for="tag in tagList"
      :to="tag.path"
      :style="{'font-size':  tag.articlesNum > 20 ? '1.5rem' : tag.articlesNum < 14 ? '1rem': `${tag.articlesNum * 1.5}px`, color: cloudColorList[tag.articlesNum % cloudColorList.length] }"
    >{{ tag.name }}</RouterLink>
  </div>
</template>
<script setup>
import { RouterLink } from "vue-router";
import config from "../../public/config";
import { store } from "@/stores/store.js";
const state = store();
const { cloudColorList } = config;
const tags = state.tags;
const tagList = [];

for (const tag in tags) {
  tagList.push({ name: tag, path: "", articlesNum: tag.length });
}
</script>

<style lang='scss' scoped>
.tag {
  .link {
    display: inline-block;
    margin: 0.625rem;
  }

  .link:hover {
    color: var(--primary-color) !important;
  }
}
</style>
