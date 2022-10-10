<template>
  <div id="sidebar" :class="isSidebar ? 'on' : ''">
    <div class="inner panels">
      <div class="overview panel active" data-title="站点概览">
        <div class="author side--author--info">
          <img
            class="image lozaded"
            alt="Cheshire Cat"
            :data-src="sidebar.avator"
            :src="sidebar.avator"
          />
          <p class="name">{{ sidebar.author }}</p>
          <div class="description">{{ sidebar.description }}</div>
        </div>
        <nav class="state side--site--info">
          <div class="item posts">
            <router-link to="/archives">
              <span class="count">{{ sidebar.articlesNum }}</span>
              <span class="name">文章</span>
            </router-link>
          </div>
          <div class="item categories">
            <router-link to="/categories">
              <span class="count">{{ sidebar.categoriesNum }}</span>
              <span class="name">分类</span>
            </router-link>
          </div>
          <div class="item tags">
            <router-link to="/tags">
              <span class="count">{{ sidebar.tagsNum }}</span>
              <span class="name">标签</span>
            </router-link>
          </div>
        </nav>
        <div class="social side--social--link">
          <a
            v-for="link of sidebar.socialLinks"
            :key="link"
            :href="link.url"
            rel="noopener external nofollow noreferrer"
            target="_blank"
            class="exturl item"
            :class="link.name"
            :title="link.url"
          >
            <i class="ic" :class="link.icon"></i>
          </a>
        </div>
      </div>
    </div>
  </div>
</template>
<script setup>
import { toRefs } from "vue";
import config from "../../public/config";
import { store } from "@/stores/store.js";
import anime from "animejs/lib/anime.es.js";
import { RouterLink } from "vue-router";
const { sidebar } = config;
const state = store();
const { isSidebar } = toRefs(state);
</script>

<style lang='scss' scoped>
.panels {
  padding-top: 0;
}
#sidebar {
}
@media (min-width: 991px) {
  #sidebar {
    position: sticky;
    top: 0;
    transform: translateX(0) !important;
    opacity: 1 !important;
    display: block !important;
  }
}

#sidebar > .inner {
  min-height: 100vh;
}
.side--nav > a:hover {
  color: var(--grey-0) !important;
  background-color: var(--color-morandi-blue);
  box-shadow: 0 0.125rem 0.75rem var(--color-morandi-blue);
  opacity: 0.9;
  border-radius: 0.625rem;
}
.side--nav {
  border-radius: 0.625rem;
}
.side--author--info,
.side--site--info,
.side--social--link,
.side--menu {
  background: linear-gradient(to top, var(--grey-0) 0, var(--grey-1) 20%)
    no-repeat top;
  box-shadow: 0 1.25rem 1rem 0.3125rem var(--body-bg-shadow);
  padding: 20px;
}
.side--menu {
  margin-top: 0.625rem !important;
}
.side--social--link {
  margin-top: 0.625rem;
}
.side--nav {
  position: relative;
}
</style>