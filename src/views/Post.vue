<template>
  <div class="article wrap">
    <div class="breadcrumb">
      <i class="ic i-home"></i>
      <span>
        <a href="/">首页</a>
      </span>
      <i class="ic i-angle-right"></i>
      <span class="current">
        <span>
          <span>{{ articleTags }}</span>
        </span>
      </span>
      <i class="ic i-angle-right"></i>
      <span class="current">
        <span>
          <span>{{ articleTitle }}</span>
        </span>
      </span>
    </div>
    <article class="post block" lang="zh-CN">
      <div v-html="articleContent"></div>
    </article>
  </div>
</template>
<script setup>

import { store } from "@/stores/store.js";
import { ref, watch } from "vue";
import { useRoute } from "vue-router";
const route = useRoute();
const state = store();
const articleContent = ref("");
const articleTitle = ref("");
const articleTags = ref("");

watch(
  () => route.params,
  (newParams, oldParams) => {
    const { type, path } = newParams;
    const matchPath = `/${type}/${path}`;

    const { content, title, tags, index } = state.postsDic.get(matchPath);
    articleContent.value = content;
    articleTitle.value = title;
    articleTags.value = tags.join(" ");
    state.sideIndex = index
  },
  { immediate: true }
);
</script>
