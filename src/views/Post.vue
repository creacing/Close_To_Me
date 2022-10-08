<template>
  <div class="article wrap">
    <div class="breadcrumb">
      <i class="ic i-home"></i>
      <span>
        <a href="/">首页</a>
      </span>
      <i class="ic i-angle-right"></i>

      <span class="current">
        <a
          href="/categories/computer-science/note/theme-shoka-doc/"
          rel="index"
          title="分类于 Theme Shoka Documentation"
        >
          <span>Theme Shoka Documentation</span>
        </a>
        <meta content="3" />
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

watch(
  () => route.params,
  (newParams, oldParams) => {
    const { type, path } = newParams;
    const matchPath = `/${type}/${path}`;
    articleContent.value = state.postsDic.get(matchPath).content;
  },
  { immediate: true }
);
</script>
