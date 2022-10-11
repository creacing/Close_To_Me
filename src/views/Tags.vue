<template>
  <div class="collapse wrap">
    <h2 class="item title">
      <RouterLink to="/">标签</RouterLink>
      <small>/</small>
      {{ tagsNum }}
    </h2>
    <div class="tag cloud">
      <RouterLink
        :key="tag"
        v-for="tag in tagList"
        :to="tag.path"
        :style="{
          'font-size':
            tag.articlesNum > 20
              ? '30px'
              : tag.articlesNum < 14
              ? '20px'
              : `${tag.articlesNum*1.5}px`,
          color: cloudColorList[tag.articlesNum % cloudColorList.length],
        }"
      >{{ tag.name }}</RouterLink>
    </div>

    <div>xxxxxxxxxxxxxxxxxx</div>
  </div>
</template>
<script setup>
import { RouterLink } from "vue-router";
import config from "../../public/config";
import { store } from "@/stores/store.js";
const state = store();
const { cloudColorList } = config;
const tags = state.tags;
const tagsNum = Object.values(tags).length;
const tagList = [];

for (const tag in tags) {
  tagList.push({ name: tag, path: "", articlesNum: tag.length });
}
</script>
