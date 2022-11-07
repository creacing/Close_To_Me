<template>
  <div class="wrap">
    <div class="bread">
      <i class="ic i-feather"></i>
      <span>
        <a href="/">首页</a>
      </span>
      <i class="ic i-angle-right"></i>
      <span class="current">
        <span>{{ articleTags }}</span>
      </span>
      <i class="ic i-angle-right"></i>
      <span class="current">
        <span>{{ articleTitle }}</span>
      </span>
    </div>
    <article class="post">
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

    const existArticle = state.postsDic.get(matchPath)
    if (existArticle) {
      const { content, title, tags, index } = existArticle
      articleContent.value = content;
      articleTitle.value = title;
      articleTags.value = tags.join(" ");
      state.sideIndex = index;
    }

  },
  { immediate: true }
);
</script>

<style lang="scss" scoped>
.bread {
  display: inline-flex;
  font-size: 0.8125em;
  align-items: center;
  margin: 1.25rem 0;
  flex-wrap: wrap;
}

.bread .ic {
  margin: 0 0.125rem;
  color: var(--grey-4);
}

.bread .ic:nth-child(1) {
  margin-left: 0;
  margin-right: 0.3125rem;
}

.bread span {
  white-space: pre;
}

.bread span.current {
  background-color: var(--color-red-a1);
  border-radius: 0.625rem;
  padding: 0 0.625rem;
  transition: all 0.2s ease-in-out 0s;
}

.bread span.current span {
  white-space: normal;
}

.bread span.current a {
  color: var(--primary-color);
}

.bread span.current:hover {
  background-color: var(--color-red-a3);
}

.post header {
  font-size: 1.125em;
  margin-bottom: 0.625rem;
}

.post header .title {
  font-size: 1.5em;
  margin: initial;
  text-align: center;
  overflow-wrap: break-word;
  word-wrap: break-word;
  padding-bottom: 0.625rem;
}

.post header .link {
  display: inline-block;
  position: relative;
  vertical-align: top;
}

.post header .link .i-link-alt {
  font-size: 0.875em;
  margin-left: 0.3125rem;
}

.post header .meta {
  text-align: center;
  border-top: 0.0625rem dashed var(--grey-9-a1);
  font-family: Mulish, -apple-system, "PingFang SC", "Microsoft YaHei",
    sans-serif;
}

.post .meta {
  color: var(--grey-5);
  font-size: 0.75em;
  text-align: right;
}

.post .meta .item {
  display: inline-block;
  margin-right: 0.625rem;
}

.post .meta .icon {
  margin-right: 0.1875rem;
}

.post footer::before {
  content: "";
  width: 100%;
  height: 0.0625rem;
  background: var(--grey-3);
  display: block;
  margin: 1.25rem auto 0;
}

.post .tags {
  text-align: left;
  margin-top: 0.625rem;
  font-size: 0.75em;
}

.post .tags a {
  display: inline-block;
  position: relative;
  padding: 0 0.3125rem;
  border-radius: 0.3125rem;
  background: var(--note-bg);
  color: var(--note-text);
}

.post .tags a:not(:last-child) {
  margin-right: 0.625rem;
}

.post .tags a:before {
  content: "";
  position: absolute;
  bottom: 0;
  height: 100%;
  width: 0;
  right: 0;
  background: var(--color-red-a1);
  border-radius: 0.25rem;
  transition: all 0.2s ease-in-out 0s;
}

.post .tags a:hover {
  color: var(--primary-color);
}

.post .tags a:hover:before {
  width: 104%;
  left: -2%;
}

@media (max-width: 567px) {
  .post .eof {
    margin: 2.5rem auto 1.25rem !important;
  }
}
@media (max-width: 991px) {
  .post .meta .icon {
    display: inline-block;
  }
}
</style>
